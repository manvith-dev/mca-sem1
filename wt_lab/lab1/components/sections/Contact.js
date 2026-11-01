import { H2 } from "../ui/Typography.js";

export function Contact() {
    return `
    <div class="flex flex-col p-8 md:p-16 gap-6">
        ${H2("Contact")}
        ${ContactForm()}
        <div class="flex flex-col gap-4 p-4 justify-center items-center">
            <p><span class="text-neutral-400 font-medium">Email:</span> <span class="text-lg">poojarymanvith2005@gmail.com</span> </p>
            <p><span class="text-neutral-400 font-medium">Phone No:</span> <span class="text-lg">(+91) 9156691445</span> </p>
        </div>
    </div>
    `;
}

function ContactForm() {
    return `
        <form onsubmit="event.preventDefault(); window.alert('Email sent');" class="flex flex-col p-8 gap-4 w-full items-center">
            <h3 class="text-2xl font-bold">Send an e-mail</h3>
            
            <label class="flex flex-col w-full sm:w-1/3">
                <p class="text-sm text-neutral-500 font-medium">Your Name:</p>
                <input class="border p-4 rounded-md" type="text" placeholder="Enter your name" />
            </label>
            <label class="flex flex-col w-full sm:w-1/3">
                <p class="text-sm text-neutral-500 font-medium">Your Email:</p>
                <input class="border p-4 rounded-md" type="text" placeholder="Enter your email" />
            </label>

            <label class="flex flex-col w-full sm:w-1/3">
                <p class="text-sm text-neutral-500 font-medium">Message:</p>
                <textarea class="border p-4 rounded-md"></textarea>
            </label>

            <button type="submit" class="bg-purple-600 px-4 py-2 rounded-full cursor-pointer hover:bg-purple-800 hover:rounded-md">
                Send Email
            </button>
        </form>

    `;
}