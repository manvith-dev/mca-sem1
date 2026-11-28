import data from "../../../data/students.json";
const students = data.students;

export const averagePerSubject = [
    {
        "subject": "Java",
        "average": averageMarksOfSubject("Java")
    },
    {
        "subject": "DBMS",
        "average": averageMarksOfSubject("DBMS"),
    },
    {
        "subject": "WT",
        "average": averageMarksOfSubject("WT"),
    },
    {
        "subject": "DSA",
        "average": averageMarksOfSubject("DSA")
    }
]


function averageMarksOfSubject(subject) {
    let totalMarks = 0;
    students.map((student) => (
        totalMarks += student.marks[subject]
    ))
    return totalMarks / students.length;
}