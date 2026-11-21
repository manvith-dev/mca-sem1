import data from "../../../data/students.json";
const studentsData = data.students;

export const performanceData = [
    { name: "Excellent", value: 0, fill: "#8b5cf6" },
    { name: "Good", value: 0, fill: "#3b82f6" },
    { name: "Average", value: 0, fill: "#f59e0b" },
    { name: "Needs Improvement", value: 0, fill: "#ef4444" },
];

function assignStudentsPerformance() {
    studentsData.map((student) => {
        let totalMarks = 0;
        totalMarks += student.marks.Java
        totalMarks += student.marks.DBMS
        totalMarks += student.marks.WT
        totalMarks += student.marks.DSA
        let avg = totalMarks / 4;

        if (avg > 80) {
            performanceData[0].value += 1;
        } else if (avg > 70) {
            performanceData[1].value += 1;
        } else if (avg > 60) {
            performanceData[2].value += 1;
        } else {
            performanceData[3].value += 1;
        }

    })
}

assignStudentsPerformance();