# 🎓 Student Performance Dashboard

A web-based dashboard designed to monitor student academic performance, attendance, and overall progress. It provides visual insights, student records, and performance tracking through an interactive interface.

## ✨ Implemented Features

- **Dashboard Overview:** Displays total students, average attendance, average marks, and number of at-risk students.
- **Performance Analytics:** Interactive bar chart showing average marks by subject.
- **Performance Distribution:** Pie chart comparing performing students and at-risk students.
- **Performance Trends:** Line chart to compare individual student marks across subjects.
- **Student Records:** Displays student ID, name, class, attendance, average marks, assignment completion, and performance status.
- **Search & Filters:** Search students by name or ID and filter records by class or performance status.
- **Student Details:** View detailed academic information, including subject-wise marks and attendance.
- **Performance Leaderboard:** Displays the top 5 students based on average marks.
- **At-Risk Identification:** Automatically identifies students with attendance below 75% or average marks below 40.

## 🛠️ Technologies Used

| Technology   | Purpose                             |
| ------------ | ----------------------------------- |
| React.js     | Frontend development                |
| Tailwind CSS | Styling and responsive layout       |
| Recharts     | Interactive data visualizations     |
| JavaScript   | Data processing and dashboard logic |
| JSON         | Student data storage                |
| shadcn/ui    | Table components                    |

## 📊 Performance Evaluation

Students are classified into two categories:

- **At Risk:** Attendance below 75% OR average marks below 40.
- **Performing:** Attendance of at least 75% AND average marks of at least 40.

## 📁 Data Source

Student information is loaded from a local `students.json` file. The dashboard dynamically calculates statistics, subject averages, performance categories, and leaderboard rankings using the available student records.

## 🚀 Overview

The dashboard provides a centralized view of student performance, making it easier to identify students who may need academic attention and monitor overall class progress.

---

_Student Performance Dashboard | SYMCA Academic Overview_
