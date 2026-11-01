export function WhyAttend() {
    return`
    <div class="px-8 md:px-16 lg:px-32 flex flex-col gap-4 py-8">
        <h2 class="text-2xl font-bold">Why Attend?</h2>
        
        ${Point("Learn from Experts","Gain insights from industry leaders and technology pioneers.")}
        ${Point("Discover What's Next","Explore emerging technologies and the trends transforming businesses and society.")}
        ${Point("Build Connections","Meet developers, founders, investors, researchers, and technology professionals from around the world.")}
        ${Point("Turn Ideas Into Action","Take away practical knowledge, strategies, and tools you can apply immediately.")}
        </div>
    `;
}

function Point(heading, content) {
    return `
        <div class="flex flex-col">
            <h3 class="font-bold text-lg">${heading}</h3>
            <p class="text-sm text-neutral-400">${content}</p>
        </div>
    `;
}