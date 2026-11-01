import { useState } from "react";

export function Form() {
  const [fields, setFields] = useState({ name: "", email: "", message: "" });
  const [message, setMessage] = useState("");
  function onSubmit(e) {
    e.preventDefault();

    setMessage(
      `Name: ${fields.name}, Email: ${fields.email}, Message: ${fields.message}`,
    );
  }
  return (
    <section className="flex flex-col gap-2 items-center p-2">
      <form onSubmit={onSubmit} className="flex flex-col gap-2">
        <h1>Form</h1>
        <Input
          id="name"
          field="Name"
          type="text"
          value={fields.name}
          setFields={setFields}
        />
        <Input
          id="email"
          field="Email"
          type="email"
          value={fields.email}
          setFields={setFields}
        />
        <Input
          id="message"
          field="Message"
          type="text"
          value={fields.message}
          setFields={setFields}
        />
        <div className="flex gap-4 space-between">
          <button type="submit" className="">
            Submit
          </button>
          <button
            onClick={() => {
              setFields({ name: "", email: "", message: "" });
            }}
            type="reset"
          >
            Cancel
          </button>
        </div>
      </form>
      <div className="">
        <p>{message}</p>
      </div>
    </section>
  );
}

function Input({ id, field, type, value, setFields }) {
  return (
    <div className="flex flex-col gap-1">
      <label htmlFor={id}>{field}</label>
      <input
        id={id}
        className="border rounded-md text-primary p-1"
        type={type}
        value={value}
        onChange={(e) =>
          setFields((prev) => ({
            ...prev,
            [id]: e.target.value,
          }))
        }
      />
    </div>
  );
}
