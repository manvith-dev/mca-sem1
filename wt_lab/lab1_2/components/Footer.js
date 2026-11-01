import { NavbarItem } from "./Navbar.js";

export function Footer() {
    return `
    <footer class="bg-neutral-950 flex gap-6 py-4 justify-center px-8 md:px-16 lg:px-32">
        <div class="flex flex-col p-8 items-center gap-16 w-full">
        <div class="flex flex-col sm:flex-row justify-between w-full gap-8">
            <div class="flex flex-col">
                <p class="font-bold text-xl">Tech Summit 2026</p>
                <p class="text-sm text-neutral-500">The global meeting point for technology, innovation, and ideas.</p>
            </div>
            <div class="flex flex-col gap-4">
                <p class="font-bold text-xl">Quick Links</p>
                <div class="flex flex-col gap-1">
                    ${NavbarItem("Home", "#")}
                    ${NavbarItem("About", "#about")}
                    ${NavbarItem("Speakers", "#speakers")}
                    ${NavbarItem("Schedule", "#schedule")}
                    ${NavbarItem("Register", "#register")}
                </div>
            </div>
            <div class="flex flex-col gap-4">
                <p class="font-bold text-xl">Event</p>
                <div class="flex flex-col gap-1">
                    <p>October 16 - 17, 2026</p>
                    <p>Bengaluru International Convention Centre</p>
                    <p>Bengaluru, India</p>
                </div>
                <p class="font-bold text-xl">Contact</p>
                <div class="flex flex-col gap-1">
                    <p>hello@techsummit2026.com</p>
                    <p>+91 80 4000 2026</p>
                </div>
            </div>
        </div>
            <p class="text-sm text-neutral-500">© 2026 Tech Summit. All rights reserved.</p>
        </div>
    </footer>
    `;
}
