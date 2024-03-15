# Logger documentation

<div hidden>
```
@startuml Sequence Diagram
LoggerApp -> Client: Authentication Request
Client --> LoggerApp: Authentication Response

LoggerApp -> Client: Another authentication Request
LoggerApp <-- Client: Another authentication Response
@enduml
```
</div>

![](firstDiagram.svg)
