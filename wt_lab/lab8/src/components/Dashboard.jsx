import { useEffect, useMemo, useState } from "react";
import studentData from "../data/students.json";

import {
  Table,
  TableBody,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "../components/ui/table";

import {
  BarChart,
  Bar,
  XAxis,
  YAxis,
  Tooltip,
  ResponsiveContainer,
  PieChart,
  Pie,
  Cell,
  LineChart,
  Line,
  CartesianGrid,
  Legend,
} from "recharts";

export default function Dashboard() {
  const [students, setStudents] = useState([]);
  const [search, setSearch] = useState("");
  const [selectedClass, setSelectedClass] = useState("ALL");
  const [selectedStatus, setSelectedStatus] = useState("ALL");
  const [selectedStudent, setSelectedStudent] = useState(null);

  // Load student data
  useEffect(() => {
    setStudents(studentData.students);
  }, []);

  // Calculate average marks for a student
  const getStudentAverage = (student) => {
    const marks = Object.values(student.marks);

    return marks.reduce((total, mark) => total + mark, 0) / marks.length;
  };

  // Identify at-risk students
  const isAtRisk = (student) => {
    return student.attendance < 75 || getStudentAverage(student) < 40;
  };

  // Dashboard statistics
  const stats = useMemo(() => {
    const totalStudents = students.length;

    if (totalStudents === 0) {
      return {
        totalStudents: 0,
        averageAttendance: 0,
        averageMarks: 0,
        atRiskCount: 0,
      };
    }

    const totalAttendance = students.reduce(
      (total, student) => total + student.attendance,
      0,
    );

    const totalMarks = students.reduce(
      (total, student) => total + getStudentAverage(student),
      0,
    );

    return {
      totalStudents,
      averageAttendance: (totalAttendance / totalStudents).toFixed(1),
      averageMarks: (totalMarks / totalStudents).toFixed(1),
      atRiskCount: students.filter(isAtRisk).length,
    };
  }, [students]);

  // Search and filtering
  const filteredStudents = useMemo(() => {
    return students.filter((student) => {
      const matchesSearch =
        student.name.toLowerCase().includes(search.toLowerCase()) ||
        student.id.toLowerCase().includes(search.toLowerCase());

      const matchesClass =
        selectedClass === "ALL" || student.class === selectedClass;

      const matchesStatus =
        selectedStatus === "ALL" ||
        (selectedStatus === "AT RISK" && isAtRisk(student)) ||
        (selectedStatus === "PERFORMING" && !isAtRisk(student));

      return matchesSearch && matchesClass && matchesStatus;
    });
  }, [students, search, selectedClass, selectedStatus]);

  // Average marks for each subject
  const subjectData = useMemo(() => {
    if (students.length === 0) return [];

    const subjects = Object.keys(students[0].marks);

    return subjects.map((subject) => ({
      subject,
      average: Number(
        (
          students.reduce(
            (total, student) => total + student.marks[subject],
            0,
          ) / students.length
        ).toFixed(1),
      ),
    }));
  }, [students]);

  // Performance distribution
  const performanceData = [
    {
      name: "Performing",
      value: students.filter((student) => !isAtRisk(student)).length,
    },
    {
      name: "At Risk",
      value: students.filter(isAtRisk).length,
    },
  ];

  // Leaderboard - top 5 students
  const leaderboard = useMemo(() => {
    return [...students]
      .sort((a, b) => getStudentAverage(b) - getStudentAverage(a))
      .slice(0, 5);
  }, [students]);

  // Line chart data
  const lineData = filteredStudents.map((student) => ({
    name: student.name,
    ...student.marks,
  }));

  const chartColors = ["#8b5cf6", "#f97316"];

  return (
    <div className="min-h-screen bg-neutral-950 text-neutral-100 p-6 md:p-10">
      {/* Header */}
      <header className="mb-10 flex flex-col gap-2 md:flex-row md:items-center md:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">
            Student Dashboard
          </h1>
          <p className="text-neutral-400 mt-2">
            Monitor student performance and academic progress.
          </p>
        </div>

        <div className="rounded-lg border border-neutral-800 bg-neutral-900 px-4 py-2 text-sm text-neutral-300">
          SYMCA Academic Overview
        </div>
      </header>

      {/* Statistics Cards */}
      <section className="grid grid-cols-1 sm:grid-cols-2 xl:grid-cols-4 gap-5 mb-10">
        <StatCard
          title="Total Students"
          value={stats.totalStudents}
          subtitle="Registered students"
          icon="👨‍🎓"
        />

        <StatCard
          title="Average Attendance"
          value={`${stats.averageAttendance}%`}
          subtitle="Overall attendance"
          icon="📅"
        />

        <StatCard
          title="Average Marks"
          value={stats.averageMarks}
          subtitle="Across all subjects"
          icon="📊"
        />

        <StatCard
          title="At-Risk Students"
          value={stats.atRiskCount}
          subtitle="Require attention"
          icon="⚠️"
          danger
        />
      </section>

      {/* Bar and Pie Charts */}
      <section className="grid grid-cols-1 lg:grid-cols-2 gap-6 mb-6">
        {/* Bar Chart */}
        <div className="bg-neutral-900 border border-neutral-800 rounded-xl p-6">
          <h2 className="text-lg font-semibold mb-1">
            Average Marks by Subject
          </h2>

          <p className="text-sm text-neutral-400 mb-6">
            Overall subject-wise performance
          </p>

          <div className="h-[300px]">
            <ResponsiveContainer width="100%" height="100%">
              <BarChart data={subjectData}>
                <XAxis dataKey="subject" stroke="#a3a3a3" />
                <YAxis domain={[0, 100]} stroke="#a3a3a3" />
                <Tooltip
                  contentStyle={{
                    backgroundColor: "#171717",
                    border: "1px solid #404040",
                    borderRadius: "8px",
                  }}
                />
                <Bar
                  dataKey="average"
                  name="Average Marks"
                  fill="#8b5cf6"
                  radius={[6, 6, 0, 0]}
                />
              </BarChart>
            </ResponsiveContainer>
          </div>
        </div>

        {/* Pie Chart */}
        <div className="bg-neutral-900 border border-neutral-800 rounded-xl p-6">
          <h2 className="text-lg font-semibold mb-1">Student Performance</h2>

          <p className="text-sm text-neutral-400 mb-6">
            Performing students vs students at risk
          </p>

          <div className="h-[300px]">
            <ResponsiveContainer width="100%" height="100%">
              <PieChart>
                <Pie
                  data={performanceData}
                  dataKey="value"
                  nameKey="name"
                  cx="50%"
                  cy="50%"
                  innerRadius={65}
                  outerRadius={105}
                  paddingAngle={4}
                >
                  {performanceData.map((entry, index) => (
                    <Cell key={entry.name} fill={chartColors[index]} />
                  ))}
                </Pie>

                <Tooltip />
                <Legend />
              </PieChart>
            </ResponsiveContainer>
          </div>
        </div>
      </section>

      {/* Line Chart */}
      <section className="bg-neutral-900 border border-neutral-800 rounded-xl p-6 mb-10">
        <h2 className="text-lg font-semibold mb-1">
          Student Performance Trends
        </h2>

        <p className="text-sm text-neutral-400 mb-6">
          Compare subject-wise marks across students
        </p>

        <div className="h-[350px]">
          <ResponsiveContainer width="100%" height="100%">
            <LineChart data={lineData}>
              <CartesianGrid strokeDasharray="3 3" stroke="#404040" />

              <XAxis
                dataKey="name"
                stroke="#a3a3a3"
                angle={-25}
                textAnchor="end"
                height={70}
                interval={0}
              />

              <YAxis domain={[0, 100]} stroke="#a3a3a3" />

              <Tooltip
                contentStyle={{
                  backgroundColor: "#171717",
                  border: "1px solid #404040",
                  borderRadius: "8px",
                }}
              />

              <Legend />

              <Line
                type="monotone"
                dataKey="Java"
                stroke="#8b5cf6"
                strokeWidth={2}
                dot={false}
              />

              <Line
                type="monotone"
                dataKey="DBMS"
                stroke="#22c55e"
                strokeWidth={2}
                dot={false}
              />

              <Line
                type="monotone"
                dataKey="WT"
                stroke="#f97316"
                strokeWidth={2}
                dot={false}
              />

              <Line
                type="monotone"
                dataKey="DSA"
                stroke="#3b82f6"
                strokeWidth={2}
                dot={false}
              />
            </LineChart>
          </ResponsiveContainer>
        </div>
      </section>

      {/* Student Records */}
      <section className="bg-neutral-900 border border-neutral-800 rounded-xl p-6 mb-10">
        <div className="mb-6">
          <h2 className="text-xl font-semibold">Student Records</h2>

          <p className="text-sm text-neutral-400 mt-1">
            Search, filter and view student information.
          </p>
        </div>

        {/* Search and Filters */}
        <div className="flex flex-col md:flex-row gap-3 mb-6">
          <input
            type="text"
            placeholder="Search by name or ID..."
            value={search}
            onChange={(e) => setSearch(e.target.value)}
            className="flex-1 bg-neutral-950 border border-neutral-700 rounded-lg px-4 py-2.5 outline-none focus:border-purple-500"
          />

          <select
            value={selectedClass}
            onChange={(e) => setSelectedClass(e.target.value)}
            className="bg-neutral-950 border border-neutral-700 rounded-lg px-4 py-2.5 outline-none"
          >
            <option value="ALL">All Classes</option>
            {[...new Set(students.map((s) => s.class))].map((cls) => (
              <option key={cls} value={cls}>
                {cls}
              </option>
            ))}
          </select>

          <select
            value={selectedStatus}
            onChange={(e) => setSelectedStatus(e.target.value)}
            className="bg-neutral-950 border border-neutral-700 rounded-lg px-4 py-2.5 outline-none"
          >
            <option value="ALL">All Students</option>
            <option value="PERFORMING">Performing</option>
            <option value="AT RISK">At Risk</option>
          </select>
        </div>

        {/* Table */}
        <Table>
          <TableHeader>
            <TableRow className="border-neutral-700 hover:bg-transparent">
              <TableHead className="text-neutral-400">ID</TableHead>
              <TableHead className="text-neutral-400">Name</TableHead>
              <TableHead className="text-neutral-400">Class</TableHead>
              <TableHead className="text-neutral-400">Attendance</TableHead>
              <TableHead className="text-neutral-400">Average Marks</TableHead>
              <TableHead className="text-neutral-400">Assignments</TableHead>
              <TableHead className="text-neutral-400">Status</TableHead>
              <TableHead className="text-neutral-400">Details</TableHead>
            </TableRow>
          </TableHeader>

          <TableBody>
            {filteredStudents.map((student) => (
              <TableRow
                key={student.id}
                className="border-neutral-800 hover:bg-neutral-800/60"
              >
                <TableCell>{student.id}</TableCell>

                <TableCell className="font-medium">{student.name}</TableCell>

                <TableCell>{student.class}</TableCell>

                <TableCell>
                  <span
                    className={
                      student.attendance < 75
                        ? "text-red-400"
                        : "text-green-400"
                    }
                  >
                    {student.attendance}%
                  </span>
                </TableCell>

                <TableCell>{getStudentAverage(student).toFixed(1)}</TableCell>

                <TableCell>
                  {student.assignments.completed}/{student.assignments.total}
                </TableCell>

                <TableCell>
                  <span
                    className={`px-2.5 py-1 rounded-full text-xs font-medium ${
                      isAtRisk(student)
                        ? "bg-red-500/10 text-red-400"
                        : "bg-green-500/10 text-green-400"
                    }`}
                  >
                    {isAtRisk(student) ? "At Risk" : "Performing"}
                  </span>
                </TableCell>

                <TableCell>
                  <button
                    onClick={() => setSelectedStudent(student)}
                    className="text-purple-400 hover:text-purple-300 font-medium"
                  >
                    View
                  </button>
                </TableCell>
              </TableRow>
            ))}

            {filteredStudents.length === 0 && (
              <TableRow>
                <TableCell
                  colSpan={8}
                  className="text-center text-neutral-400 py-10"
                >
                  No students found.
                </TableCell>
              </TableRow>
            )}
          </TableBody>
        </Table>

        <p className="text-sm text-neutral-500 mt-4">
          Showing {filteredStudents.length} of {students.length} students
        </p>
      </section>

      {/* Student Details */}
      {selectedStudent && (
        <section className="bg-neutral-900 border border-purple-500/30 rounded-xl p-6 mb-10">
          <div className="flex justify-between items-center mb-6">
            <div>
              <h2 className="text-xl font-semibold">Student Details</h2>
              <p className="text-sm text-neutral-400 mt-1">
                Detailed academic information
              </p>
            </div>

            <button
              onClick={() => setSelectedStudent(null)}
              className="text-neutral-400 hover:text-white"
            >
              ✕ Close
            </button>
          </div>

          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-4 gap-5">
            <DetailItem label="Student ID" value={selectedStudent.id} />
            <DetailItem label="Name" value={selectedStudent.name} />
            <DetailItem label="Class" value={selectedStudent.class} />
            <DetailItem
              label="Attendance"
              value={`${selectedStudent.attendance}%`}
            />

            {Object.entries(selectedStudent.marks).map(([subject, marks]) => (
              <DetailItem
                key={subject}
                label={subject}
                value={`${marks}/100`}
              />
            ))}

            <DetailItem
              label="Average Marks"
              value={getStudentAverage(selectedStudent).toFixed(1)}
            />

            <DetailItem
              label="Assignments Completed"
              value={`${selectedStudent.assignments.completed}/${selectedStudent.assignments.total}`}
            />

            <DetailItem
              label="Performance Status"
              value={isAtRisk(selectedStudent) ? "At Risk" : "Performing"}
            />
          </div>
        </section>
      )}

      {/* Leaderboard */}
      <section className="bg-neutral-900 border border-neutral-800 rounded-xl p-6">
        <h2 className="text-xl font-semibold">🏆 Performance Leaderboard</h2>

        <p className="text-sm text-neutral-400 mt-1 mb-6">
          Top 5 students based on average marks.
        </p>

        <div className="space-y-3">
          {leaderboard.map((student, index) => (
            <div
              key={student.id}
              className="flex items-center justify-between bg-neutral-950 border border-neutral-800 rounded-lg p-4"
            >
              <div className="flex items-center gap-4">
                <span className="text-lg font-bold text-purple-400">
                  #{index + 1}
                </span>

                <div>
                  <p className="font-medium">{student.name}</p>
                  <p className="text-xs text-neutral-500">
                    {student.id} · {student.class}
                  </p>
                </div>
              </div>

              <span className="font-semibold text-green-400">
                {getStudentAverage(student).toFixed(1)}%
              </span>
            </div>
          ))}
        </div>
      </section>
    </div>
  );
}

// Reusable statistic card
function StatCard({ title, value, subtitle, icon, danger }) {
  return (
    <div className="bg-neutral-900 border border-neutral-800 rounded-xl p-5">
      <div className="flex justify-between items-center mb-4">
        <p className="text-sm text-neutral-400">{title}</p>
        <span className="text-xl">{icon}</span>
      </div>

      <h2
        className={`text-3xl font-bold ${
          danger ? "text-red-400" : "text-neutral-100"
        }`}
      >
        {value}
      </h2>

      <p className="text-xs text-neutral-500 mt-2">{subtitle}</p>
    </div>
  );
}

// Reusable student detail item
function DetailItem({ label, value }) {
  return (
    <div className="bg-neutral-950 border border-neutral-800 rounded-lg p-4">
      <p className="text-sm text-neutral-500 mb-2">{label}</p>
      <p className="font-semibold">{value}</p>
    </div>
  );
}
