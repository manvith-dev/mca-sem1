import { Navbar } from "./components/ui/Navbar.js";
import { Hero } from "./components/sections/Hero.js";
import { Academics } from "./components/sections/Academics.js";
import { Skills } from "./components/sections/Skills.js";
import { Projects } from "./components/sections/Projects.js";
import { Contact } from "./components/sections/Contact.js";
import { Footer } from "./components/sections/Footer.js";

function Home() {
    return `
        ${Navbar()}
        <main>
            ${Hero()}
        </main>
        <section id="academics">
            ${Academics()}
        </section>
        <section id="skills">
            ${Skills()}
        </section>
        <section id="projects">
            ${Projects()}
        </section>
        <section id="contact">
            ${Contact()}
        </section>
        ${Footer()}
    `;
}

document.querySelector("#app").innerHTML = Home();