import { H2 } from "../ui/Typography.js";

export function Projects() {
    return `
    <div class="flex flex-col p-8 md:p-16 gap-8">
        ${H2("Projects")}
        <div class="flex flex-col sm:flex-row gap-4">
        <div class="flex-1">
            <a href="https://leetpulse.vercel.app" target="_blank">
                <div class=" h-full flex flex-col items-center p-1 border rounded-md border-neutral-600 justify-between gap-2 sm:max-w-[35vw]">
                    <img  src="assets/leetpulseUIonLaptopFrame.png">
                    <p class="font-medium underline text-lg">leetpulse - A Spaced Repetition Tracker</p>
                    <ul class="px-8 py-4 text-neutral-400 text-justify list-disc">
                        <li>A full-stack spaced repetition platform for structured LeetCode revision.</li>
                        <li>Integrated the Gemini API for AI-assisted problem insights.</li>
                        <li>Designed a responsive React interface using Tailwind CSS.</li>
                    </ul>
                </div>
            </a>
            </div>
            <div class="flex-1">
            <a href="https://dalmiacodefest.vercel.app/project" target="_blank">
                <div class="flex flex-col items-center p-1 border rounded-md border-neutral-600 justify-between gap-2 sm:max-w-[35vw]">
                    <img src="assets/DCFUIonLaptopFrame.png">
                    <p class="font-medium underline text-lg">DCF - Dalmia Code Fest 1.0</p>
                    <ul class="px-8 py-4 text-neutral-400 text-justify list-disc">
                        <li>A full-stack coding competition platform used by 27 teams (54 participants).</li>
                        <li>Developed secure team registration with backend validation and unique team IDs.</li>
                        <li> Implemented a multi-round quiz system with automated response tracking.</li>
                    </ul>
                </div>
            </a>
            </div>
        </div>
    </div>
    `;
}