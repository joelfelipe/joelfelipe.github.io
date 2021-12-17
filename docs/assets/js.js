
    function excluir(tag){
        if(this.document.getElementById('totalizador')["value"] == 0){
            alert("Nâo é possível excluir!");
        }else{
            var nome = 'botoesEtiquetas' + tag;
            document.getElementById(nome).outerHTML = '';
            this.document.getElementById('totalizador')["value"] -= 1;
        }
    };
/*
    var rng;
    function posiciona(){ 
        rng = document.body.createTextRange();
        rng.moveToPoint(window.event.x, window.event.y);
    };
    function inserir(tag) {
        if (rng) rng.text=""+tag+"";
            document.form1.insere.focus();
    };*/

    function tags(qnt) {
        var nome = 'botao' + qnt;
        var tag = document.getElementById(nome)["value"];
        //console.log(tag);
        var texto = document.getElementById('default')["value"];
        //console.log(texto);
        var posicao = document.getElementById('posicao')["value"];
        document.getElementById('default')["value"] = texto.slice(0, posicao) + " " + tag + " " + texto.slice(posicao);
        
        //var teste = document.getSelection().createRange().text;
        //console.log(teste);
        //var selectText = document.selection.createRange().text;
    
        //if(selectText != "") {
            //var expr = "<" + tag + ">";
            //var formatTag = "<" + tag + ">" + selectText + "</" + tag + ">";
            //document.selection.createRange().text = formatTag;			
        //} else {
        //}
    };


