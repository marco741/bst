### PER I COLLABORATORI DA NETBEANS

## Come caricare le proprie versioni di "bst" direttamente da NetBeans

Per caricare la tua personale versione della libreria e contribuire al suo sviluppo direttamente da NetBeans occorre eseguire i seguenti passaggi:

1. Aggiorna la tue versione della libreria con git -> remote -> pull...
2. Crea un nuovo branch tramite git -> branch/tag -> create branch... ed inserisci un nome che lasci comprendere il senso delle tue modifiche globali.
3. Verificare di aver switchato correttamente al branch appena creato tramite git -> branch/tag -> switch to branch... <Nome Nuovo Branch>
4. Esegui tutte le modifiche che ritieni opportune
5. Ad ogni modifica logica commissiona il cambiamento tramite git -> commit, aggiungendo volta per volta un messaggio esplicativo che lasci comprendere agli altri utenti il senso del tuo singolo cambiamento. 
Esempio: Hai intenzione di correggere un bug e di modificare un errore di battitura all'interno di una printf. Il flusso di lavoro dovrebbe somigliare al seguente:
    - Correzione bug
    - git -> commit..., messaggio: "Corretto un bug che faceva crashare il programma"
    - Correzione errore di battitura
    - git -> commit..., messaggio: "Corretto un errore di battitura della printf all'interno della funzione "my error" ".
6. Quando ti senti pronto a rendere pubblico il tuo lavoro e tutte le modifiche commissionate fare git -> remote -> push..., facendo attenzione a selezionare i propri dati account di github, e il branch all'interno del quale si sta lavorando (non master);

### DAJE TI HO ANCHE SCRITTO LE ISTRUZIONI DAMMI IL TUO CODICE :Q__ :D

@francescobabbaro :+1: Fai del tuo meglio! :shipit:
