import { BarChart, XAxis, YAxis, Bar, ResponsiveContainer } from "recharts";
import { averagePerSubject } from "./data/avgMarksPerSubject";

export function AverageMarksPerSubject() {
  return (
    <div className="w-full h-[350px]">
      <ResponsiveContainer width="100%" height="100%">
        <BarChart data={averagePerSubject}>
          <XAxis dataKey="subject" />
          <YAxis />
          <Bar dataKey="average" fill="#8b5cf6" />
        </BarChart>
      </ResponsiveContainer>
    </div>
  );
}
