import { Link } from "react-router-dom";
export function Navbar() {
    return (
        <nav className="border-b flex justify-between w-full">
            <NavbarMenu>
                <NavbarMenuItem path="/">
                    Amazon2.0
                </NavbarMenuItem>
            </NavbarMenu>
            <NavbarMenu>
                <NavbarMenuItem path="/">Home</NavbarMenuItem>
                <NavbarMenuItem path="/products">Products</NavbarMenuItem>
                <NavbarMenuItem path="/cart">Cart</NavbarMenuItem>
            </NavbarMenu>
        </nav>
    );
}
function NavbarMenu({children}) {
    return (
        <div className="flex gap-2 items-center justify-center px-4 py-1">
            {children}
        </div>
    );
}
function NavbarMenuItem({path, children}) {
    return (
        <Link to={path} className="no-link-decoration">
            <div  className="menu-item p-1 items-center justify-center">
                {children}
            </div>
        </Link>
    )
}