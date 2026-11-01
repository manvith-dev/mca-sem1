import { NavbarMenuItem } from "../ui/Navbar.js";

export function Footer() {
    return `
        <div class="flex flex-col items-center justify-center bg-neutral-950 p-8">
            <div class="flex flex-col sm:flex-row gap-8 py-8">
                <div class="flex flex-col px-8">
                    <span class="text-purple-500 text-5xl uppercase font-bold tracking-relaxed">Manvith Poojary</span>
                    <span class="text-lg ">Full Stack Web Developer</span>
                </div>
                <div class="flex flex-col gap-4 px-8">
                    <div class="text-lg font-medium">Quick Links</div>
                    <div class="flex flex-col gap-1">
                        ${NavbarMenuItem("Home", "#")}    
                        ${NavbarMenuItem("Academics", "#academics")}    
                        ${NavbarMenuItem("Skills", "#skills")}    
                        ${NavbarMenuItem("Projects", "#projects")}    
                        ${NavbarMenuItem("Contact", "#contact")}
                    </div>
                </div>
                <div class="flex flex-col gap-4 px-8">
                    <div>Social Media</div>
                    <div class="flex flex-col gap-1">
                        ${NavbarMenuItem("GitHub", "https://github.com/manvith-dev")}    
                        ${NavbarMenuItem("Instagram", "https://www.instagram.com/manvith.dev")}
                    </div>
                </div>
            </div>
            <div class="text-sm text-neutral-500"> &copy; ${new Date().getFullYear()}, manvith-dev </div>
        </div>
    `;
}