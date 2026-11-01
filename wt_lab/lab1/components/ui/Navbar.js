export function Navbar() {
    return (
        `
        <nav class="top-0 sticky bg-neutral-900/80 border-b border-neutral-700 flex flex-row justify-center items-center p-6 gap-4 sm:gap-8 text-sm md:text-md">
        ${NavbarMenuItem("Home", "#")}    
        ${NavbarMenuItem("Academics", "#academics")}    
        ${NavbarMenuItem("Skills", "#skills")}    
        ${NavbarMenuItem("Projects", "#projects")}    
        ${NavbarMenuItem("Contact", "#contact")}    
        </nav>
        `
    );
}

export function NavbarMenuItem(text, href) {
    return `<a href="${href}" class="cursor-pointer hover:text-purple-400">${text}</a>`;
}