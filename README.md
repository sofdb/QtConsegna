Proggetto: applicazione per la gestione di un catalogo di prodotti per la Nail Art che permette di creare, modificare, cancellare e visualizzare i propri prodotti (CRUD)

La cartella principale `QtNailsProjectConsegna` contiene:
- `relazione\`  
  - `RelazioneQt.pdf` 
  - `QtNailsUML.jpg` 

- `QtProject_src\`  
  - Codice sorgente completo suddiviso in cartelle `logic\`, `UI\`, `Json\`
  - E' presente anche una cartella `images\` con immagini presenti nel file `catalogo.json`
  - File `catalogo.json` con prodotti di esempio (per testare i messaggi di "catalogo vuoto" e "creazione catalogo", 
    basterà spostarlo fuori dalla cartella di compilazione)
  - File `QtNailsProject.pro` per la compilazione 
  - File `resources.qrc` che include il foglio di stile `style.qss` (presente nella cartella `UI\`)

Per compilare il progetto:

```bash
cd QtProject_src
qmake QtNailsProject.pro
make
./QtNailsProject
