import { Form } from "./components/Form.js";
import { handleSubmit } from "./components/Form.js";

function Home() {

    return `
    <main class="flex w-[100vw] h-[100vh] items-center justify-center">
        ${Form()}
    </main>
    `
}

document.querySelector("#app").innerHTML = Home();

const form1 = document.querySelector("#form-1");
form1.addEventListener("submit", handleSubmit);