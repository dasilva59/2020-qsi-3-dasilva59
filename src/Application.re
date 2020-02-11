[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let innerContent =
    switch (url.path) {
    |[] => <p> {React.string("Bienvenue sur ma page d'accueil")} </p> 
    |["greeting"] =><Greeting />
    |["blinking"] =><BlinkingGreeting>{React.string("Hello")}</BlinkingGreeting>
    |["reducer"] =><ReducerFromReactJSDocs />
    |["fetchedDogpictures"] =><FetchedDogPictures />
    |["fetchedRandomDog"] =><FetchRandomDog />
    | _ => <p> {React.string("Erreur 404 : rien à voir ici")} </p> 
    };
    <>
    <h1> {React.string("Mon super site")} </h1>
    <ul>
      <li onClick={_ => ReasonReactRouter.push("/greeting")}>
        {React.string("Greeting")}
      </li>
      <li onClick={_ => ReasonReactRouter.push("/blinking")}>
      {React.string("BlinkingGreeting")}
    </li>
    <li onClick={_ => ReasonReactRouter.push("/reducer")}>
    {React.string("ReducerFromReactJSDocs")}
    </li>
    <li onClick={_ => ReasonReactRouter.push("/fetchedDogpictures")}>
    {React.string("FetchedDogPictures")}
  </li>
  <li onClick={_ => ReasonReactRouter.push("/fetchedRandomDog")}>
  {React.string("FetchRandomDog")}
</li>
    </ul>
    {innerContent}
  </>
};