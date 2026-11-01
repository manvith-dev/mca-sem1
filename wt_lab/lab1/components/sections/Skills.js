import { H2 } from "../ui/Typography.js";
import { Capsule } from "../ui/Capsule.js";

export function Skills() {
    return `
    <div class="flex flex-col p-8 md:p-16 gap-8">
        ${H2("Skills")}
        <div class="flex flex-col gap-2">
            <h3 class="text-lg font-medium">Languages</h3>
            <div class="flex gap-4">
                ${Capsule("Typescript")}
                ${Capsule("Python")}
                ${Capsule("C++")}
            </div>
            <h3 class="text-lg font-medium">Frontend</h3>
            <div class="flex gap-4">
                ${Capsule("Next.js")}
                ${Capsule("Tailwind CSS")}
                ${Capsule("React")}
                ${Capsule("HTML")}
            </div>
            <h3 class="text-lg font-medium">Backend & Database</h3>
            <div class="flex gap-4">
                ${Capsule("MongoDB")}
                ${Capsule("REST APIs")}
                ${Capsule("Next.js API Routes")}
            </div>
            <h3 class="text-lg font-medium">Tools & Workflow</h3>
            <div class="flex gap-4">
                ${Capsule("Git")}
                ${Capsule("GitHub")}
                ${Capsule("Figma")}
            </div>
            <h3 class="text-lg font-medium">Currently Exploring</h3>
            <div class="flex gap-4">
                ${Capsule("DSA")}
                ${Capsule("Web Components")}
            </div>
        </div>
    </div>
    `;
}