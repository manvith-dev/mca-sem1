export function Button(text, href) {
    return `
        <a href=${href}>
            <button class="bg-purple-600 py-2 px-6 rounded-lg cursor-pointer hover:bg-purple-800 hover:rounded-sm">
                ${text}
            </button>
        </a>
    `;
}