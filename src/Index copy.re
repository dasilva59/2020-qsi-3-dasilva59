// Entry point


[@bs.val] external document: Js.t({..}) = "document";

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

   switch (url.path) {
    |["AtomicGreeting",_] => <Greeting />;
    | ["BlinkingGreeting",_] => <Greeting />;
    | ["ReducerFromReactJSDocs",_] =><Greeting />;
    | ["FetchedDogpictures",_] => <Greeting />;
    | ["FetchedRandomDog",_] =><Greeting />;
    | ["All",_] =><Greeting />;
    };

  }


// We're using raw DOM manipulations here, to avoid making you read
// ReasonReact when you might precisely be trying to learn it for the first
// time through the examples later.
let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= ExampleStyles.style;

let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};


let handleClick = (href, _event) => {

  ReasonReactRouter.push(href);

};


let form = (text,url) => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("a");
  title##setAttribute("href", url)
  title##className #= "containerTitle";
  title##onClick #= handleClick(url)
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;

};

let menu=text=>{
  let container = document##createElement("div");
  container##className #= "menuTitle";
  

  let h=document##createElement("h1");
  h##className #= "menuTitle";
  h##innerText #= text;
  
  let () =container##appendChild(h);


  let () =document##body##appendChild(container);
  container;
};


ReactDOMRe.render({React.string("Menu Principal")},menu("Menu Principal"));

ReactDOMRe.render(<Router/>,makeContainer("Application"));

// All 4 examples.
ReactDOMRe.render({React.string("")},form("Atomic Greeting","/AtomicGreeting"));

ReactDOMRe.render(
  {React.string("")},form("Blinking Greeting","/BlinkingGreeting")
);

ReactDOMRe.render(
  {React.string("")},form("ReducerFromReactJSDocs","/ReducerFromReactJSDocs")
);

ReactDOMRe.render(
  {React.string("")},form("Fetched Dog pictures","/FetchedDogpictures")
);

ReactDOMRe.render({React.string("")},form("Fetched Random Dog","/FetchedRandomDog"));

ReactDOMRe.render({React.string("")},form("All","/All"));
