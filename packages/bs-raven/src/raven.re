type static;

type options;

type transportOptions;

type autoBreadcrumbOptions;

type instrumentationOptions;

type breadcrumb;

type userContext;

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

[@bs.obj]
external makeOptions :
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

[@bs.module] external raven : static = "raven-js";

[@bs.module "raven-js"] external lastEventId : unit => string = "";

[@bs.module "raven-js"] external lastException : unit => Js.Exn.t = "";

[@bs.send.pipe: static] external install : unit => static = "";

[@bs.module "raven-js"] external uninstall : unit => static = "";

[@bs.module "raven-js"]
external config : (~dsn: string, ~options: options) => static = "";

[@bs.module "raven-js"]
external captureMessage : (~msg: string, ~options: options=?, unit) => static =
  "";

[@bs.module "raven-js"]
external captureException :
  (~exn: Js.Exn.t, ~options: options=?, unit) => static =
  "";

[@bs.module "raven-js"] external captureBreadcrumb : breadcrumb => static = "";

[@bs.module "raven-js"] external setUserContext : userContext => static = "";

[@bs.module "raven-js"]
external clearUserContext : unit => static = "setUserContext";

[@bs.module "raven-js"] external setExtraContext : Js.t('a) => static = "";

[@bs.module "raven-js"] external setTagsContext : Js.t('a) => static = "";

[@bs.module "raven-js"] external setRelease : string => static = "";

[@bs.module "raven-js"] external setDSN : string => static = "";

[@bs.module "raven-js"] external setEnvironment : string => static = "";

[@bs.module "raven-js"] external isSetup : unit => bool = "";

[@bs.module "raven-js"] external showReportDialog : Js.t('a) => unit = "";

/*  this is probably very bad */
external unsafeToJsExn : exn => Js.Exn.t = "%identity";