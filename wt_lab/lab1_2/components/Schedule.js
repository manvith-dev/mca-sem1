export function Schedule() {
    return `
    <div class="px-8 md:px-16 lg:px-32 flex flex-col gap-4 py-8">
        <h2 class="text-2xl font-bold">Schedule</h2>
        
        <div class="flex flex-col gap-2">
            <h3 class="text-xl font-bold">Day 1</h3>
            <div class="flex flex-col gap-4" >
                ${TimeEventVenue("09:00 AM", "Registration & Welcome Coffee", "Networking Lounge")}
                ${TimeEventVenue("10:00 AM", "Opening Keynote: Building the Intelligent Future", "Main Stage · Aarav Mehta")}
                ${TimeEventVenue("11:00 AM", "The Next Generation of AI", "Innovation Hall · Marcus Johnson")}
                ${TimeEventVenue("12:00 PM", "Networking Lunch", "Summit Lounge")}
                ${TimeEventVenue("01:30 PM", "Cloud Computing at Scale", "Main Stage · Sophia Williams")}
                ${TimeEventVenue("02:30 PM", "Cybersecurity in a Connected World", "Tech Hall · Daniel Kim")}
                ${TimeEventVenue("04:00 PM", "Startup Innovation Showcase", "Innovation Hall")}
            </div>
        </div>

        <div class="flex flex-col gap-2">
            <h3 class="text-xl font-bold">Day 2</h3>
            <div class="flex flex-col gap-4" >
                ${TimeEventVenue("09:30 AM", "Future of Digital Finance", "Main Stage · Ananya Rao")}
                ${TimeEventVenue("10:00 AM", "Robotics & Intelligent Automation", "Innovation Hall")}
                ${TimeEventVenue("11:30 AM", "Building Sustainable Technology", "Tech Hall · Elena García")}
                ${TimeEventVenue("12:30 PM", "Networking Lunch", "Summit Lounge")}
                ${TimeEventVenue("02:00 PM", "The Developer Experience of Tomorrow", "Developer Zone")}
                ${TimeEventVenue("04:00 PM", "Technology Leaders Panel", "Main Stage")}
                ${TimeEventVenue("05:00 PM", "Closing Keynote & Summit Wrap-Up", "Main Stage")}
            </div>
        </div>
    </div>
    `;
}

export function TimeEventVenue(time, event, venue) {
    return `
    <div class="flex flex-col">
        <p class="font-bold">${time} — ${event}</p>
        <p class="text-sm text-neutral-400">${venue}</p>
    </div>
    `
}

