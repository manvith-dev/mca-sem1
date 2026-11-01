export function Speakers() {
    return`
    <div class="px-8 md:px-16 lg:px-32 flex flex-col gap-4 py-8">
        <h2 class="text-2xl font-bold">Speakers</h2>
        <div class="grid grid-col-2 md:grid-col-4 lg:grid-cols-5 grid-rows-auto">
            ${SpeakerItro("Aarav Mehta","CEO, Nexora Technologies")}
            ${SpeakerItro("Sophia Williams","VP of Engineering, CloudSphere")}
            ${SpeakerItro("Daniel Kim","Founder, CyberCore Labs")}
            ${SpeakerItro("Ananya Rao","Chief Product Officer, Finova")}
            ${SpeakerItro("Marcus Johnson","AI Research Scientist, NeuralWorks")}
            ${SpeakerItro("Elena García","Founder, GreenTech Innovations")}
        </div>
        </div>
    `;
}

export function SpeakerItro(name, about) {
    return `<div class="flex flex-col items-center col-span-1 p-4 gap-4">
            <img class="w-24 rounded-full"src="assets/blank_profile.jpg">
            <div class="flex flex-col items-center">
                <h3 class="font-bold">${name}</h3>
                <p class="text-xs text-neutral-400 text-center">${about}</p>
            </div>
        </div>`;
}