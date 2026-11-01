import { Button } from "./Button.js";

export function Hero() {
    return `
    <div class="h-[90vh] px-8 md:px-16 lg:px-32 py-8 justify-center flex flex-col gap-6">
        <div>
            <div class="text-purple-500 text-5xl uppercase font-bold">Tech Summit 2026</div>
            <div class="text-2xl font-bold">The Future of Technology Starts Here</div>
            <p class="text-sm text-neutral-400 sm:w-[50vw]">Join thousands of technology leaders, developers, entrepreneurs, innovators, and visionaries for two days of ideas, innovation, and meaningful connections.</p>
        </div>
        <div class="">
            <div class="font-bold">October 16-17, 2026</div>
            <div class="">Bengaluru International Convention Centre, Bengaluru, India</div>
        </div>
        <div>
            ${Button("Register Now", "#register")}
        </div>
    </div>
    `;
}