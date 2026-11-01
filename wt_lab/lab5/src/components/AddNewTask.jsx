export default function AddNewTask({ onAdd }) {
  function handleSubmit(e) {
    e.preventDefault();
    const title = e.target.taskTitle.value.trim();

    if (!title) return;

    onAdd(title);
    e.target.reset();
  }
  return (
    <>
      <form className="flex gap-1" onSubmit={handleSubmit}>
        <input type="text" placeholder="Add new task" name="taskTitle" />
        <button type="submit" className="btn-primary">
          Add
        </button>
      </form>
    </>
  );
}
