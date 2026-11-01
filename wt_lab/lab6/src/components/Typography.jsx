export function H1({children}) {
    return (
        <h1 className="h1-class">
            {children}
        </h1>
    )
}

export function H3({children}) {
    return (
        <h3 className="h3-class">
            {children}
        </h3>
    )
}

export function Muted({className, children}) {
    return (
        <p className={"text-muted " + className}>
            {children}
        </p>
    )
}   