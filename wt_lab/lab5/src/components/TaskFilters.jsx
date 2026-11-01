export default function TaskFilters({ onChange }) {
  return (
    <div className="flex gap-1">
      <button
        onClick={() => {
          onChange("All");
        }}
      >
        All
      </button>
      <button
        onClick={() => {
          onChange("Active");
        }}
      >
        Active
      </button>
      <button
        onClick={() => {
          onChange("Completed");
        }}
      >
        Completed
      </button>
    </div>
  );
}
