import { Navbar } from "./components/Navbar.js";
import { Hero } from "./components/Hero.js";
import { WhyAttend } from "./components/WhyAttend.js";
import { Speakers } from "./components/Speakers.js";
import { Schedule } from "./components/Schedule.js";
import { Registration } from "./components/Registration.js";
import { Footer } from "./components/Footer.js";

function Home() {
    return `
    ${Navbar()}
        <main>
            ${Hero()}
        </main>
        <section id="about">
            ${WhyAttend()}
        </section>
        <section id="speakers">
            ${Speakers()}
        </section>
        <section id="schedule">
            ${Schedule()}
        </section>
        <section id="register">
            ${Registration()}
        </section>
        ${Footer()}
    `;
}

document.querySelector("#app").innerHTML = Home();