type static;

type options;

type transportOptions;

type autoBreadcrumbOptions;

type instrumentationOptions;

type userContext;

type breadcrumb;

[@bs.obj]
external makeConfig :
  (
    ~release: string=?,
    ~level: [@bs.string] [ | `info | `critical | `error | `warning | `debug]=?,
    ~logger: string=?,
    ~environment: string=?,
    ~serverName: string=?,
    ~ignoreErrors: array(string)=?,
    ~ignoreUrls: array(string)=?,
    ~whitelistUrls: array(string)=?,
    ~includePaths: array(string)=?,
    ~tags: Js.Dict.t(string)=?,
    ~stacktrace: bool=?,
    ~extra: Js.t('a)=?,
    ~fingerprint: array(string)=?,
    ~dataCallback: 'a => 'b=?,
    ~shouldSendCallback: 'a => bool=?,
    ~maxMessageLength: int=?,
    ~maxUrlLength: int=?,
    ~transport: transportOptions => unit=?,
    ~headers: Js.Dict.t(string)=?,
    ~fetchParameters: Js.Dict.t(string)=?,
    ~allowSecretKey: bool=?,
    ~instrument: instrumentationOptions=?,
    ~autoBreadcrumbs: autoBreadcrumbOptions=?,
    ~maxBreadcrumbs: int=?,
    ~breadcrumbCallback: 'a => 'b=?,
    ~sampleRate: float=?,
    ~allowDuplicates: bool=?,
    unit
  ) =>
  options =
  "";

[@bs.obj]
external makeUserContext :
  (~id: string=?, ~username: string=?, ~email: string=?, unit) => userContext =
  "";

[@bs.obj]
external makeBreadcrumb :
  (
    ~message: string=?,
    ~category: string=?,
    ~level: [@bs.string] [ | `info | `critical | `error | `warning | `debug]=?,
    ~_type: [@bs.string] [ | `navigation | `http]=?,
    unit
  ) =>
  breadcrumb =
  "";

module Internal = {
  type dsn = string;
  [@bs.send.pipe: static] external configOnylDns : dsn => static = "config";
  [@bs.send.pipe: static]
  external config : (dsn, options) => static = "config";
};

[@bs.module] external instance : static = "raven-js";

[@bs.send.pipe: static] external install : unit => unit = "";

/* let config = (~dsn: string, ~config: option(options)=?, inst) =>
   switch config {
   | None => inst |> Internal.configOnylDns(dsn)
   | Some(c) => inst |> Internal.config(dsn, c)
   }; */
[@bs.send.pipe: static]
external config : (~dsn: string, ~config: options, unit) => static = "";

[@bs.send.pipe: static]
external captureException : Js.Exn.t => static = "captureException";

[@bs.send.pipe: static]
external captureExceptionWithOptions : (Js.Exn.t, options) => static =
  "captureException";

[@bs.send.pipe: static]
external captureMessage : string => static = "captureMessage";

[@bs.send.pipe: static]
external captureMessageWithOptions : (string, options) => static =
  "captureMessage";

[@bs.send.pipe: static] external captureBreadcrumb : breadcrumb => static = "";

[@bs.send.pipe: static] external setUserContext : userContext => static = "";

[@bs.send.pipe: static] external setExtraContext : Js.t('a) => static = "";

[@bs.send.pipe: static] external setTagsContext : Js.t('a) => static = "";

/* When passing undefined to setUserContext raven-js implicitly clears the context */
[@bs.send.pipe: static]
external clearUserContext : unit => static = "setUserContext";

external unsafeToJsExn : exn => Js.Exn.t = "%identity";