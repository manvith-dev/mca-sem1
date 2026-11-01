import { Button } from "../ui/Button.js";

export function Hero() {
    return `
    <div class="flex p-8 md:p-16 h-[80vh]">
        <div class="flex flex-col flex-1 justify-center gap-8">
            <div class="flex flex-col">
                <span class="text-purple-500 text-5xl uppercase font-bold tracking-relaxed">Manvith Poojary</span>
                <span class="text-lg">Full Stack Web Developer</span>
                <p class="text-neutral-400">I’m an IT student and developer who likes turning ideas into clean, functional software. Currently exploring web development, DSA, and building things from scratch.</p>
            </div>
            ${Button("Contact", "#contact")}
        </div>

        <div class="hidden md:flex flex-1 ">
        <img class="" alt="" src="./assets/leetpulse on laptop mockup.png">
        </div>
    </div>
    `;
}