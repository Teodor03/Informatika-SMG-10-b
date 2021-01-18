package edu.school.pizzaorderingsystem;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.Color;
import javax.swing.SwingConstants;
import javax.swing.table.DefaultTableModel;
import javax.swing.JPanel;
import javax.swing.JLayeredPane;
import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class Pizza_ordering_system {

	private JFrame frame;
	private JLabel lblTitle;
	private JRadioButton rdbtnSmall;
	private final ButtonGroup buttonGroup = new ButtonGroup();
	private JRadioButton rdbtnMedium;
	private JRadioButton rdbtnLarge;
	private JRadioButton rdbtnExtralarge;
	private JButton btnAdd;
	private JButton btnCalcBalance;
	private JLabel lblQty;
	private JSpinner Qty_spinner;
	private JButton btnRemove;
	private JLabel lblTotal;
	private JTextField txtTotal;
	private JLabel lblPayment;
	private JTextField txtPayment;
	private JLabel lblBalance;
	private JTextField txtBalance;
	private JScrollPane pnlTable;
	private JTable table;
	private DefaultTableModel model; 
	
	private String[] table_collums = {"Item","Price","Qty","Total"};
	
	private int n=0,all_price=0;
	//private String [][] table_data;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Pizza_ordering_system window = new Pizza_ordering_system();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Pizza_ordering_system() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setResizable(false);
		frame.setBounds(100, 100, 700, 350);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		lblTitle = new JLabel("Pizza ordering System");
		lblTitle.setHorizontalAlignment(SwingConstants.CENTER);
		lblTitle.setBackground(Color.BLUE);
		lblTitle.setOpaque(true);
		lblTitle.setForeground(Color.YELLOW);
		lblTitle.setFont(new Font("Arial", Font.BOLD, 24));
		lblTitle.setBounds(10, 10, 676, 50);
		frame.getContentPane().add(lblTitle);
		
		rdbtnSmall = new JRadioButton("Small");
		buttonGroup.add(rdbtnSmall);
		rdbtnSmall.setBounds(30, 100, 103, 21);
		frame.getContentPane().add(rdbtnSmall);
		
		rdbtnMedium = new JRadioButton("Medium");
		buttonGroup.add(rdbtnMedium);
		rdbtnMedium.setBounds(30, 135, 103, 21);
		frame.getContentPane().add(rdbtnMedium);
		
		rdbtnLarge = new JRadioButton("Large");
		buttonGroup.add(rdbtnLarge);
		rdbtnLarge.setBounds(30, 169, 103, 21);
		frame.getContentPane().add(rdbtnLarge);
		
		rdbtnExtralarge = new JRadioButton("Extra Large");
		buttonGroup.add(rdbtnExtralarge);
		rdbtnExtralarge.setBounds(30, 202, 103, 21);
		frame.getContentPane().add(rdbtnExtralarge);
		
		btnAdd = new JButton("Add");
		btnAdd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int val=0,num;
				String type=""; 
				if(rdbtnSmall.isSelected()) {
					type="Small";
					val=200;
				}
				if(rdbtnMedium.isSelected()) {
					type="Medium";
					val=400;
				}
				if(rdbtnLarge.isSelected()) {
					type="Large";
					val=600;
				}
				if(rdbtnExtralarge.isSelected()) {
					type="Extra Large";
					val=600;
				}
				if(type=="") {
					return;
				}
				num=(int)Qty_spinner.getValue();
				all_price+=val*num;
				Object[] a = {type,val,num,val*num};
				model.addRow(a);
				n++;
				buttonGroup.clearSelection();
				txtTotal.setText(""+all_price);
				txtBalance.setText("");
				txtPayment.setText("");
				return;
			}
		});
		btnAdd.setBounds(30, 272, 85, 21);
		frame.getContentPane().add(btnAdd);
		
		btnCalcBalance = new JButton("Calc balance");
		btnCalcBalance.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int a;
				try {
				a = Integer.parseInt(txtPayment.getText());
				}catch(Exception exc) {return;}
				txtBalance.setText(""+(a-all_price));
				return;
			}
		});
		btnCalcBalance.setBounds(125, 272, 109, 21);
		frame.getContentPane().add(btnCalcBalance);
		
		lblQty = new JLabel("Qty");
		lblQty.setBounds(244, 276, 21, 13);
		frame.getContentPane().add(lblQty);
		
		Qty_spinner = new JSpinner();
		Qty_spinner.setModel(new SpinnerNumberModel(new Integer(1), new Integer(1), null, new Integer(1)));
		Qty_spinner.setBounds(275, 273, 70, 20);
		frame.getContentPane().add(Qty_spinner);
		
		btnRemove = new JButton("Remove");
		btnRemove.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(n==0) {
					return;
				}
				n--;
				all_price -= (int)model.getValueAt(n, 3);
				model.removeRow(n);
				txtTotal.setText(""+all_price);
			}
		});
		btnRemove.setBounds(355, 272, 85, 21);
		frame.getContentPane().add(btnRemove);
		
		lblTotal = new JLabel("Total");
		lblTotal.setBounds(571, 90, 96, 13);
		frame.getContentPane().add(lblTotal);
		
		txtTotal = new JTextField();
		txtTotal.setBounds(571, 113, 96, 19);
		frame.getContentPane().add(txtTotal);
		txtTotal.setColumns(10);
		
		lblPayment = new JLabel("Payment");
		lblPayment.setBounds(571, 139, 96, 13);
		frame.getContentPane().add(lblPayment);
		
		txtPayment = new JTextField();
		txtPayment.setBounds(571, 162, 96, 19);
		frame.getContentPane().add(txtPayment);
		txtPayment.setColumns(10);
		
		lblBalance = new JLabel("Balance");
		lblBalance.setBounds(571, 191, 96, 13);
		frame.getContentPane().add(lblBalance);
		
		txtBalance = new JTextField();
		txtBalance.setBounds(571, 214, 96, 19);
		frame.getContentPane().add(txtBalance);
		txtBalance.setColumns(10);
		
		model = new DefaultTableModel();
		table = new JTable(model);
		table.setEnabled(false);
		model.addColumn(table_collums[0]);
		model.addColumn(table_collums[1]);
		model.addColumn(table_collums[2]);
		model.addColumn(table_collums[3]);
		
		pnlTable = new JScrollPane(table);
		table.setFillsViewportHeight(true);
		pnlTable.setBounds(150, 80, 410, 162);
		frame.getContentPane().add(pnlTable);


	}
}
