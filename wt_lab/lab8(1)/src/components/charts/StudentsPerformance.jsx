import {
  PieChart,
  Pie,
  Cell,
  Tooltip,
  Legend,
  ResponsiveContainer,
} from "recharts";

import { performanceData } from "./data/performanceData";

export default function StudentsPerformance() {
  return (
    <div className="w-full h-[350px]">
      <ResponsiveContainer width="100%" height="100%">
        <PieChart>
          <Pie
            data={performanceData}
            dataKey={"value"}
            nameKey={"name"}
            cx="50%"
            cy="50%"
            outerRadius={110}
            innerRadius={65}
            paddingAngle={3}
          ></Pie>
        </PieChart>
      </ResponsiveContainer>
    </div>
  );
}
