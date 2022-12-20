# Examination modul 3 - Store stock

Modul 3 har introducerat arv, polymorfism och generisk programmering.
Denna examinationsuppgift ämnar därför examinera dessa koncept.

---

Ett lagersystem ska skapas. Alla nödvändiga klasser existerar redan med tomma
medlemsfunktioner, och din uppgift är att färdigställa dessa.

Huvudklassen i detta system är `StoreStock`. Detta är en *behållarklass* för
produkter som tillhör tilläggning, hantering och hämtande av objekt som ärver
från basklassen `Product`. Klassen `StoreStock` känner INTE till någon av de
klasstyper som ärver från `Product`, så `StoreStock` kan enbart interagera med
med produktobjekt genom polymorfism och i vissa fall mallar (templates).

Basklassen `Product` agerar gränssnitt för alla typer av produkter. Detta
gränssnitt ger stöd att hämta pris, förklaring av produkten samt volymen som
krävs för att lagra den fysiska produkten (exempelivs på en lagerhylla).

Klasshierarkin under `Product` ser ut enligt följande i denna uppgift:
```
             Product
        /-------^------------\
     Shovel          PerishableProduct
                /------------^------------\
              Milk                    EggPackage
```

Instruktioner för varje klass och funktion hittar du i klassernas header- och
källfiler. För att kunna provköra din kod får du även en main-fil med lite tips
på hur systemet *kan* användas. Notera att alla funktioner inte används i denna
fil, så fortsätt arbeta i denna fil för att själv ta reda på att allt fungerar
som tänkt.

Följande filer ska lämnas in:
- `StoreStock.hpp` (Obs! Detta är den enda headerfilen pga. mallar)
- `StoreStock.cpp`
- `Product.cpp`
- `Shovel.cpp`
- `PerishableProduct.cpp`
- `EggPackage.cpp`
- `Milk.cpp`

## Kriterier vid inlämning:
- Klasser och funktioner ska följa instruktioner som medföljer i filerna.
- Kod ska vara skriven på engelska och hålla en god, logisk struktur.
- Namn på funktioner och variabler ska vara självförklarande.
- Utkommenterad kod ska tas bort innan inlämning.
- Globala variabler är ej tillåtna.
- Endast de `#include` som redan finns i filerna får användas.
    - Andra `#include` får användas under utveckling, men måste tas bort (inte utkommenteras) innan inlämning.
