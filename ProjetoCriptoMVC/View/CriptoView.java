package View;

import Model.Cripto;
import javax.swing.JOptionPane;


public class CriptoView {
    
     public Cripto getCriptoData(){
        Cripto cripto = new Cripto();
        cripto.setName(JOptionPane.showInputDialog("Digite o nome da criptomoeda: "));
        cripto.setInitials(JOptionPane.showInputDialog("Digite a sigla da criptomoeda: "));       
        cripto.setRanking(Integer.parseInt(JOptionPane.showInputDialog("Digite o ranking atual da criptomoeda")));
        return cripto;
    }
    
    public void showCriptoData(Cripto cripto) {
        String text = "DADOS DA CRIPTOMOEDA" + "\n" +
                "Nome: " + cripto.getName() + "\n" +
                "Sigla: " + cripto.getInitials() + "\n" +
                "Ranking: " + cripto.getRanking();
        JOptionPane.showMessageDialog(null, text);
    }
    
}
