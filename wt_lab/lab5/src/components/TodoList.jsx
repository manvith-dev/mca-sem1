export default function ToDoList({ task, onToggle }) {
  return (
    <>
      <div className="flex flex-row">
        <input
          type="checkbox"
          checked={task.completed}
          onChange={() => onToggle(task.id)}
        />
        <div className={`flex p-1 ${task.completed ? "strikethrough" : ""}`}>
          {task.title}
        </div>
      </div>
    </>
  );
}
