export function Registration() {
    return `
    <div class="px-8 md:px-16 lg:px-32 flex flex-col gap-4 py-8">
        <h2 class="text-2xl font-bold">Registration</h2>
        ${RegistrationForm()}
        </div>
    `;
}

function RegistrationForm() {
    return `
    <form onsubmit="event.preventDefault(); window.alert('Registration done');" class="flex flex-col gap-6 items-center">
        <label class="w-full sm:w-1/2 lg:w-1/3">
            <p class="font-bold text-sm">Full Name</p>
            <input class="w-full placeholder:text-neutral-400 border border-neutral-400 p-2 rounded-md" type="text" placeholder="Enter your name">
        </label>
        <label class="w-full sm:w-1/2 lg:w-1/3">
            <p class="font-bold text-sm">Email Address</p>
            <input class="w-full placeholder:text-neutral-400 border border-neutral-400 p-2 rounded-md" type="email" placeholder="Enter your email address">
        </label>
        <label class="w-full sm:w-1/2 lg:w-1/3">
            <p class="font-bold text-sm">Company / Organization</p>
            <input class="w-full placeholder:text-neutral-400 border border-neutral-400 p-2 rounded-md" type="text" placeholder="Enter your organization">
        </label>
        <label class="w-full sm:w-1/2 lg:w-1/3">
            <p class="font-bold text-sm">Job Title</p>
            <input class="w-full placeholder:text-neutral-400 border border-neutral-400 p-2 rounded-md" type="text" placeholder="Enter your job title">
        </label>
        <div class="w-full sm:w-1/2 lg:w-1/3 flex flex-col items-start">
            <p class="font-bold text-sm">Ticket Type</p>
            <div class="flex justify-center gap-2">
                <input class="cursor-pointer border border-neutral-400 p-2 rounded-md" name="ticket" type="radio" value="standardPass"> Standard Pass
            </div>
            <div class="flex justify-center gap-2">
                <input class="cursor-pointer border border-neutral-400 p-2 rounded-md" name="ticket" type="radio" value="professionalPass"> Professional Pass
            </div>
            <div class="flex justify-center gap-2">
                <input class="cursor-pointer border border-neutral-400 p-2 rounded-md" name="ticket" type="radio" value="studentPass"> Student Pass
            </div>
        </div>
        
        <button type="submit" class="bg-purple-600 py-2 px-6 rounded-lg cursor-pointer hover:bg-purple-800 hover:rounded-sm"> Register </button>
        
    </form>
    `;
}