import React, { useState } from "react";
import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Legend,
  ResponsiveContainer,
} from "recharts";

import data from "../../data/students.json";

export default function StudentMarksLineChart() {
  const [selectedClass, setSelectedClass] = useState("ALL");

  const chartData = data.students
    .filter((s) => selectedClass === "ALL" || s.class === selectedClass)
    .map((s) => {
      const avg =
        (s.marks.Java + s.marks.DBMS + s.marks.WT + s.marks.DSA) / 4;
      return {
        id: s.id,
        name: s.name,
        class: s.class,
        attendance: s.attendance,
        Java: s.marks.Java,
        DBMS: s.marks.DBMS,
        WT: s.marks.WT,
        DSA: s.marks.DSA,
        average: Number(avg.toFixed(1)),
      };
    });

  return (
    <div style={{ width: "100%", height: 420 }}>
      <div style={{ marginBottom: 12 }}>
        <label htmlFor="class-filter">Filter by class: </label>
        <select
          id="class-filter"
          value={selectedClass}
          onChange={(e) => setSelectedClass(e.target.value)}
        >
          <option value="ALL">All (SYMCA-A & SYMCA-B)</option>
          <option value="SYMCA-A">SYMCA-A</option>
          <option value="SYMCA-B">SYMCA-B</option>
        </select>
      </div>

      <ResponsiveContainer width="100%" height="100%">
        <LineChart
          data={chartData}
          margin={{ top: 10, right: 24, left: 0, bottom: 60 }}
        >
          <CartesianGrid strokeDasharray="3 3" />
          <XAxis
            dataKey="name"
            angle={-35}
            textAnchor="end"
            interval={0}
            height={70}
          />
          <YAxis domain={[0, 100]} />
          <Tooltip />
          <Legend verticalAlign="top" height={36} />
          <Line type="monotone" dataKey="Java" stroke="#2563eb" dot={{ r: 3 }} />
          <Line type="monotone" dataKey="DBMS" stroke="#16a34a" dot={{ r: 3 }} />
          <Line type="monotone" dataKey="WT" stroke="#d97706" dot={{ r: 3 }} />
          <Line type="monotone" dataKey="DSA" stroke="#dc2626" dot={{ r: 3 }} />
        </LineChart>
      </ResponsiveContainer>
    </div>
  );
}