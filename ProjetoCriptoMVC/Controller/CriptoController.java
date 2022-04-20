package Controller;

import Model.Cripto;
import Persistence.Storage;
import View.CriptoView;
import javax.swing.JOptionPane;

public class CriptoController {

    public static void main(String[] args) {
        Cripto cripto = new Cripto();
        CriptoView criptoView = new CriptoView();
        Storage storage = new Storage();

        while (true) {
            int menu = Integer.parseInt(JOptionPane.showInputDialog("SISTEMA DE CRIPTOMOEDAS" + "\n"
                    + "[1] Cadastrar" + "\n"
                    + "[2] Consultar" + "\n"
                    + "[3] Sair"));
            //int option = Integer.parseInt(JOptionPane.showInputDialog(menu));

            switch (menu) {
                case 1: {
                    cripto = criptoView.getCriptoData();
                    if (storage.create(cripto)) {
                        JOptionPane.showMessageDialog(null, "Criptomoeda " +cripto.getName() + " cadastrada com sucesso!");
                    } else {
                        JOptionPane.showMessageDialog(null, "Erro ao cadastrar a criptomoeda " + cripto.getName() + "!");
                    }
                    break;
                }
                case 2: {
                    String initials = JOptionPane.showInputDialog("Digite a sigla da criptomoeda que deseja consultar.");
                    cripto = storage.read(initials);
                    criptoView.showCriptoData(cripto);
                    break;
                }
                case 3: {
                    JOptionPane.showMessageDialog(null, "Encerrando a aplicação!");
                    System.exit(0);
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }

}
