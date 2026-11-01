function H2(text) {
    return `
        <div class="flex flex-col w-full">
            <h2 class="text-4xl font-bold">${text}</h2>
            <div class="bg-neutral-700 h-[1px]"></div>
        </div>
    `;
}

export { H2 };