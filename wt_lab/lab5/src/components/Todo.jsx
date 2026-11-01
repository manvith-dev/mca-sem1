import { useState } from "react";
import TaskFilters from "./TaskFilters";
import AddNewTask from "./AddNewTask";
import ToDoList from "./TodoList";

export default function Todo() {
  const [tasks, setTasks] = useState([
    { id: 1, title: "Save gotham city", completed: false },
    { id: 2, title: "Skip leg day", completed: false },
  ]);
  const [curState, setCurState] = useState("All");

  function toggleTask(id) {
    setTasks((prevTasks) =>
      prevTasks.map((task) =>
        task.id === id ? { ...task, completed: !task.completed } : task,
      ),
    );
  }

  function addTask(taskTitle) {
    if (!taskTitle) {
      return;
    }

    setTasks((prevTasks) => [
      ...prevTasks,
      {
        id: Date.now(),
        title: taskTitle,
        completed: false,
      },
    ]);
  }

  return (
    <>
      <div className="flex flex-col bg2 border p-2 rounded-md gap-2 w-1-2">
        <h1>ToDo List</h1>
        <AddNewTask onAdd={addTask} />
        <TaskFilters onChange={setCurState} />
        <div className="flex flex-col gap-1">
          {tasks.map((task) => {
            if (curState === "Active" && task.completed) return null;
            if (curState === "Completed" && !task.completed) return null;
            return <ToDoList key={task.id} task={task} onToggle={toggleTask} />;
          })}
        </div>
      </div>
    </>
  );
}
