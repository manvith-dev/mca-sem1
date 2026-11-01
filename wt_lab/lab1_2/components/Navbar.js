export function Navbar() {
    return `
    <nav class="bg-neutral-900/80 sticky top-0 sm:top-4 flex gap-6 p-4 justify-center border-b sm:border border-neutral-700 sm:mx-8 sm:my-4 sm:rounded-full">
        ${NavbarItem("Home", "#")}
        ${NavbarItem("About", "#about")}
        ${NavbarItem("Speakers", "#speakers")}
        ${NavbarItem("Schedule", "#schedule")}
        ${NavbarItem("Register", "#register")}
    </nav>
    `;
}

export function NavbarItem(text, href) {
    return `
    <a href="${href}">
        <span class="text-xs sm:text-md lg:text-lg hover:text-purple-500 cursor-pointer">${text}</span>
    </a>
    `
}