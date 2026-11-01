export function Button(text, href) {
    return `
        <a href="${href}">
            <button class="bg-purple-600 px-4 py-2 rounded-full cursor-pointer hover:bg-purple-800 hover:rounded-md">
                ${text}
            </button>
        </a>
    `;
}