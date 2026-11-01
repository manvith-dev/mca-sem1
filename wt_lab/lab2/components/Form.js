/*
* Tool Used: ChatGPT

* Purpose: Help with form handling, extracting form values, and input validation.

* Prompts Used:
* how to get form values using event ?
* how to use regex and what is the regex for email ?

* Personal Verification & Edits: Tested the form by submitting different inputs and verified that validation errors were displayed correctly. Made minor edits to fit the project requirements.
*/


export function Form() {

    const buttonClass = "p-2 border rounded-lg bg-olive-400 text-olive-950 hover:text-olive-50 hover:bg-olive-900 cursor-pointer font-bold text-sm";

    return `

        <form id="form-1" class="bg-olive-900 rounded-lg flex flex-col p-8 w-1/3 items-center gap-4">

            <h1 class="font-bold text-2xl">Registration Form</h1>

            <div class="flex flex-col gap-4 w-full">

                ${Input("firstName", "First Name", "fn", "Enter your first name:")}
                ${Input("lastName", "Last Name", "ln", "Enter your last name:")}
                ${Input("email", "Email", "em", "Enter your email:")}
                ${Input("userId", "User Id", "uid", "Enter your user id:")}
                ${Input("password", "Password", "pass", "Enter your password:")}
                ${Input("confirmPassword", "Confirm Password", "cnfpass", "Enter your password again:")}

                <button type="submit" class="${buttonClass}"> Submit </button>

            </div>

        </form>

    `
}

function Input(id, label, name, placeholder) {

    const inputClass = "border border-olive-400 rounded-md p-2 placehgolder:text-olive-500 text-xs w-full";
    const labelClass = "text-xs font-bold";

    return `

        <div class="flex flex-col w-full">

            <label for="${id}" class="${labelClass}"> ${label}</label>

            <div class="flex gap-4">

                <input type="text" class="${inputClass}" name="${name}" placeholder="${placeholder}">

                <div id="${id}"></div>

            </div>

        </div>

    `
}

export function handleSubmit(event) {

    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

    event.preventDefault();

    const formData = new FormData(event.target)
    const formValues = Object.fromEntries(formData.entries());

    if (formValues.fn.length < 3) {
        handleError("#firstName", "Name must have more than 3 letters")
    } else {
        removeError("#firstName");
    }

    if (formValues.ln.length == 0) {
        handleError("#lastName", "Last name must not be empty")
    } else {
        removeError("#lastName");
    }

    if (formValues.uid.length == 0) {
        handleError("#userId", "User Id cannot be empty");
    } else {
        removeError("#userId");
    }

    if (!emailRegex.test(formValues.em)) {
        handleError("#email", "Invalid email format");
    } else {
        removeError("#email");
    }

    if (formValues.pass.length < 8) {
        handleError("#password", "Password must be longer than 8 letters");
    } else {
        removeError("#password");
    }

    if (formValues.pass != formValues.cnfpass) {
        handleError("#confirmPassword", "Password and confirm password must match");
    } else {
        removeError("#confirmPassword");
    }

    return;

}

function handleError(id, error) {
    document.querySelector(id).innerHTML = `<p class='text-red-500'>${error}</p>`;
}

function removeError(id) {
    document.querySelector(id).innerHTML = "";
}