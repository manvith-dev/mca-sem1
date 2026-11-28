import {
  Table,
  TableBody,
  TableCaption,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "../components/ui/table";
import { useEffect, useState } from "react";
import studentData from "../data/students.json";
import { AverageMarksPerSubject } from "./charts/AverageMarksPerSubject";
import StudentsPerformance from "./charts/StudentsPerformance";

export default function Dashboard() {
  const [students, setStudents] = useState([]);

  useEffect(() => {
    setStudents(studentData.students);
  }, []);

  return (
    <>
      <div>Total Students: {students.length}</div>
      <div>Average Attendance: {getAverageAttendance(students) + "%"}</div>
      <div>Average Marks: {getAverageMarks(students)}</div>
      <div>At risk students: {getAtRiskStudents(students).length}</div>
      <Table>
        <TableCaption>Student Details</TableCaption>
        <TableHeader>
          <TableRow>
            <TableHead>Id</TableHead>
            <TableHead>Name</TableHead>
            <TableHead>Class</TableHead>
            <TableHead>Attendance</TableHead>
            <TableHead>Marks</TableHead>
            <TableHead>Assignments</TableHead>
            <TableHead>Status</TableHead>
          </TableRow>
        </TableHeader>
        <TableBody>
          {students.map((student) => (
            <TableRow key={student.id}>
              <TableCell>{student.id}</TableCell>
              <TableCell>{student.name}</TableCell>
              <TableCell>{student.class}</TableCell>
              <TableCell>{student.attendance}</TableCell>
              <TableCell>{student.marks.Java}</TableCell>
              <TableCell>{student.assignments.completed}</TableCell>
              <TableCell>{student.status}</TableCell>
            </TableRow>
          ))}
        </TableBody>
      </Table>
      <AverageMarksPerSubject />
      <StudentsPerformance />``
    </>
  );
}

function getAverageAttendance(data) {
  if (data.length === 0) {
    return NaN;
  }
  let totalAttendance = 0;
  data.forEach((student) => {
    totalAttendance += student.attendance;
  });
  return totalAttendance / data.length;
}

function getAverageMarks(data) {
  if (data.length === 0) {
    return NaN;
  }
  let totalMarks = 0;
  data.forEach((student) => {
    let studentMarks = student.marks;
    Object.values(studentMarks).map((marks) => (totalMarks += marks));
  });
  return totalMarks / (data.length * 4);
}

function getAtRiskStudents(data) {
  let atRiskStudents = [];
  for (let i = 0; i < data.length; i++) {
    if (data[i].attendance < 75) {
      atRiskStudents.push(data[i]);
      continue;
    }

    let totalMarks = 0;
    Object.values(data[i].marks).map((marks) => (totalMarks += marks));
    let avg = totalMarks / 4;

    if (avg < 40) {
      atRiskStudents.push(data[i]);
      continue;
    }
  }

  return atRiskStudents;
}
