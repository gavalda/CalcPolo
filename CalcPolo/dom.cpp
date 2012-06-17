#include "DOM.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "DonneeFactory.h"


Dom::Dom(Pile & pile): p(pile){}


void Dom::ecrire(QString fileName)
{
    QFile file;
    QDomDocument doc;
    QDomElement sauvegarde;
    QDomElement racine;

    QTextStream out;

    doc.clear();
    racine=doc.createElement("sauvegardes");
    doc.appendChild(racine); // filiation de la balise "sauvegarde"

    file.setFileName(fileName);
    if (!file.open(QIODevice::WriteOnly)) // ouverture du fichier de sauvegarde
        return; // en écriture
    out.setDevice(&file); // association du flux au fichier


    for(int i=0; i<p.size(); i++){
        sauvegarde=doc.createElement("sauvegarde");
        sauvegarde.setAttribute("valeur", p.at(i)->toQString());
        racine.appendChild(sauvegarde);
    }

    QDomNode noeud = doc.createProcessingInstruction("xml","version=\"1.0\"");
    doc.insertBefore(noeud,doc.firstChild());
    // sauvegarde dans le flux (deux espaces de décalage dans l'arborescence)
    doc.save(out,2);
    file.close();
}




void Dom::lire(QString fileName)
{
    QFile file;
    QDomDocument doc;
    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly)){return;}
    if (!doc.setContent(&file))
    {
        file.close(); // établit le document XML à partir des données du fichier (hiérarchie, etc.)
        return;
    }
    file.close();


    QDomElement root = doc.documentElement();
    QDomNode n = root.firstChild();
    while( !n.isNull() )
    {
      QDomElement e = n.toElement();
      if( !e.isNull() )
      {
        if( e.tagName() == "sauvegarde" )
        {
            Donnee *t;
            t=DonneeFactory::getInstance().getType(e.attribute( "valeur", "" ));

            p.push(t);

        }
      }

      n = n.nextSibling();
    }

}
