package calendarProject;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.Image;
import java.awt.Component;
import java.awt.EventQueue;
import javax.swing.JSeparator;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.net.URL;
import java.util.GregorianCalendar;
import java.awt.event.ActionEvent;
import java.awt.Rectangle;

public class Calendar extends JFrame {

	public static JPanel contentPane, panel1, panel2, panel3, panel4, panel5, panel6, panel7, panel8, panel9, panel10,
			panel11, panel12, panel13, panel14, panel15, panel16, panel17, panel18, panel19, panel20, panel21, panel22,
			panel23, panel24, panel25, panel26, panel27, panel28, panel29, panel30, panel31, panel32, panel33, panel34,
			panel35, panel36, panel37, panel38, panel39, panel40, panel41, panel42, p;
	public static JLabel p1label, p2label, p3label, p4label, p5label, p6label, p7label, p8label, p9label, p10label,
			p11label, p12label, p13label, p14label, p15label, p16label, p17label, p18label, p19label, p20label,
			p21label, p22label, p23label, p24label, p25label, p26label, p27label, p28label, p29label, p30label,
			p31label, p32label, p33label, p34label, p35label, p36label, p37label, p38label, p39label, p40label,
			p41label, p42label;
	public static JPanel notePane1, notePane2, notePane3, notePane4, notePane5, notePane6, notePane7, notePane8,
			notePane9, notePane10, notePane11, notePane12, notePane13, notePane14, notePane15, notePane16, notePane17,
			notePane18, notePane19, notePane20, notePane21, notePane22, notePane23, notePane24, notePane25, notePane26,
			notePane27, notePane28, notePane29, notePane30, notePane31, notePane32, notePane33, notePane34, notePane35,
			notePane36, notePane37, notePane38, notePane39, notePane40, notePane41, notePane42;
	public static JLabel npl1, npl2, npl3, npl4, npl5, npl6, npl7, npl8, npl9, npl10, npl11, npl12, npl13, npl14, npl15,
			npl16, npl17, npl18, npl19, npl20, npl21, npl22, npl23, npl24, npl25, npl26, npl27, npl28, npl29, npl30,
			npl31, npl32, npl33, npl34, npl35, npl36, npl37, npl38, npl39, npl40, npl41, npl42;
	private int w = 130, h = 105, x = 5, y = 5, ml = 3;
	public static JButton button, editBtn, addBtn, deleteBtn, save, cancel;
	public static String Note;
	public static JTextArea message;
	public static int slcDay, slcYear;
	public static String slcMonth;
	public boolean delete = false; // to use multiple button together
	public static boolean situation = false; // to use multiple button together
	public boolean thr = false;
	public String color = "#D3D3D3";
	public boolean edit = false;
	public boolean add = false;
	public String oldMessage;
	public Color  panelColor = new Color(41,40,38);
	
	/**
	 * Launch the application.
	 */

	public static void main(String[] args) {

		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					UIManager.setLookAndFeel("com.jtattoo.plaf.texture.TextureLookAndFeel"); // look and feel theme
					Calendar frame = new Calendar();
					ImageIcon img = new ImageIcon(
							"./icon/calendar.png");
					frame.setIconImage(img.getImage());
					frame.setVisible(true);
					frame.setResizable(false);
					frame.setTitle("CALENDAR");
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});

	}

	/**
	 * Create the frame.
	 */

	public Calendar() {
		setBounds(new Rectangle(10, 10, 1350, 700));
		Sql sql = new Sql();

		contentPane = new JPanel();
		contentPane.setAlignmentX(Component.LEFT_ALIGNMENT);
		contentPane.setBackground(Color.DARK_GRAY);
		contentPane.setBounds(40, 40, 1350, 700);
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JLabel bckImg = new JLabel();
		bckImg.setIcon(new ImageIcon("./icon/back.jpg"));
		bckImg.setBounds(0, 0, 1350, 700);
		contentPane.add(bckImg);

		// creating panels
		panel1 = new JPanel();
		panel1.setBounds(x, y, w, h);
		panel1.setBackground(panelColor);
		panel1.setLayout(null); // absolute
		x += w + ml;

		panel2 = new JPanel();
		panel2.setBounds(x, y, w, h);
		panel2.setBackground(panelColor); // color hex code
		panel2.setLayout(null);
		x += w + ml;

		panel3 = new JPanel();
		panel3.setBounds(x, y, w, h);
		panel3.setBackground(panelColor);
		panel3.setLayout(null);
		x += w + ml;

		panel4 = new JPanel();
		panel4.setBounds(x, y, w, h);
		panel4.setBackground(panelColor);
		panel4.setLayout(null);
		x += w + ml;

		panel5 = new JPanel();
		panel5.setBounds(x, y, w, h);
		panel5.setBackground(panelColor);
		panel5.setLayout(null);
		x += w + ml;

		panel6 = new JPanel();
		panel6.setBounds(x, y, w, h);
		panel6.setBackground(panelColor);
		panel6.setLayout(null);
		x += w + ml;

		panel7 = new JPanel();
		panel7.setBounds(x, y, w, h);
		panel7.setBackground(panelColor);
		panel7.setLayout(null);
		x = 5;
		y += h + ml;

		panel8 = new JPanel();
		panel8.setBounds(x, y, w, h);
		panel8.setBackground(panelColor);
		panel8.setLayout(null);
		x += w + ml;

		panel9 = new JPanel();
		panel9.setBounds(x, y, w, h);
		panel9.setBackground(panelColor);
		panel9.setLayout(null);
		x += w + ml;

		panel10 = new JPanel();
		panel10.setBounds(x, y, w, h);
		panel10.setBackground(panelColor);
		panel10.setLayout(null);
		x += w + ml;

		panel11 = new JPanel();
		panel11.setBounds(x, y, w, h);
		panel11.setBackground(panelColor);
		panel11.setLayout(null);
		x += w + ml;

		panel12 = new JPanel();
		panel12.setBounds(x, y, w, h);
		panel12.setBackground(panelColor);
		panel12.setLayout(null);
		x += w + ml;

		panel13 = new JPanel();
		panel13.setBounds(x, y, w, h);
		panel13.setBackground(panelColor);
		panel13.setLayout(null);
		x += w + ml;

		panel14 = new JPanel();
		panel14.setBounds(x, y, w, h);
		panel14.setBackground(panelColor);
		panel14.setLayout(null);
		x = 5;
		y += h + ml;

		panel15 = new JPanel();
		panel15.setBounds(x, y, w, h);
		panel15.setBackground(panelColor);
		panel15.setLayout(null);
		x += w + ml;

		panel16 = new JPanel();
		panel16.setBounds(x, y, w, h);
		panel16.setBackground(panelColor);
		panel16.setLayout(null);
		x += w + ml;

		panel17 = new JPanel();
		panel17.setBounds(x, y, w, h);
		panel17.setBackground(panelColor);
		panel17.setLayout(null);
		x += w + ml;

		panel18 = new JPanel();
		panel18.setBounds(x, y, w, h);
		panel18.setBackground(panelColor);
		panel18.setLayout(null);
		x += w + ml;

		panel19 = new JPanel();
		panel19.setBounds(x, y, w, h);
		panel19.setBackground(panelColor);
		panel19.setLayout(null);
		x += w + ml;

		panel20 = new JPanel();
		panel20.setBounds(x, y, w, h);
		panel20.setBackground(panelColor);
		panel20.setLayout(null);
		x += w + ml;

		panel21 = new JPanel();
		panel21.setBounds(x, y, w, h);
		panel21.setBackground(panelColor);
		panel21.setLayout(null);
		x = 5;
		y += h + ml;

		panel22 = new JPanel();
		panel22.setBounds(x, y, w, h);
		panel22.setBackground(panelColor);
		panel22.setLayout(null);
		x += w + ml;

		panel23 = new JPanel();
		panel23.setBounds(x, y, w, h);
		panel23.setBackground(panelColor);
		panel23.setLayout(null);
		x += w + ml;

		panel24 = new JPanel();
		panel24.setBounds(x, y, w, h);
		panel24.setBackground(panelColor);
		panel24.setLayout(null);
		x += w + ml;

		panel25 = new JPanel();
		panel25.setBounds(x, y, w, h);
		panel25.setBackground(panelColor);
		panel25.setLayout(null);
		x += w + ml;

		panel26 = new JPanel();
		panel26.setBounds(x, y, w, h);
		panel26.setBackground(panelColor);
		panel26.setLayout(null);
		x += w + ml;

		panel27 = new JPanel();
		panel27.setBounds(x, y, w, h);
		panel27.setBackground(panelColor);
		panel27.setLayout(null);
		x += w + ml;

		panel28 = new JPanel();
		panel28.setBounds(x, y, w, h);
		panel28.setBackground(panelColor);
		panel28.setLayout(null);
		x = 5;
		y += h + ml;

		panel29 = new JPanel();
		panel29.setBounds(x, y, w, h);
		panel29.setBackground(panelColor);
		panel29.setLayout(null);
		x += w + ml;

		panel30 = new JPanel();
		panel30.setBounds(x, y, w, h);
		panel30.setBackground(panelColor);
		panel30.setLayout(null);
		x += w + ml;

		panel31 = new JPanel();
		panel31.setBounds(x, y, w, h);
		panel31.setBackground(panelColor);
		panel31.setLayout(null);
		x += w + ml;

		panel32 = new JPanel();
		panel32.setBounds(x, y, w, h);
		panel32.setBackground(panelColor);
		panel32.setLayout(null);
		x += w + ml;

		panel33 = new JPanel();
		panel33.setBounds(x, y, w, h);
		panel33.setBackground(panelColor);
		panel33.setLayout(null);
		x += w + ml;

		panel34 = new JPanel();
		panel34.setBounds(x, y, w, h);
		panel34.setBackground(panelColor);
		panel34.setLayout(null);
		x += w + ml;

		panel35 = new JPanel();
		panel35.setBounds(x, y, w, h);
		panel35.setBackground(panelColor);
		panel35.setLayout(null);
		x = 5;
		y += h + ml;

		panel36 = new JPanel();
		panel36.setBounds(x, y, w, h);
		panel36.setBackground(panelColor);
		panel36.setLayout(null);
		x += w + ml;

		panel37 = new JPanel();
		panel37.setBounds(x, y, w, h);
		panel37.setBackground(panelColor);
		panel37.setLayout(null);
		x += w + ml;

		panel38 = new JPanel();
		panel38.setBounds(x, y, w, h);
		panel38.setBackground(panelColor);
		panel38.setLayout(null);
		x += w + ml;

		panel39 = new JPanel();
		panel39.setBounds(x, y, w, h);
		panel39.setBackground(panelColor);
		panel39.setLayout(null);
		x += w + ml;

		panel40 = new JPanel();
		panel40.setBounds(x, y, w, h);
		panel40.setBackground(panelColor);
		panel40.setLayout(null);
		x += w + ml;

		panel41 = new JPanel();
		panel41.setBounds(x, y, w, h);
		panel41.setBackground(panelColor);
		panel41.setLayout(null);
		x += w + ml;

		panel42 = new JPanel();
		panel42.setBounds(x, y, w, h);
		panel42.setBackground(panelColor);
		panel42.setLayout(null);

		// adding panels
		bckImg.add(panel1);
		bckImg.add(panel2);
		bckImg.add(panel3);
		bckImg.add(panel4);
		bckImg.add(panel5);
		bckImg.add(panel6);
		bckImg.add(panel7);
		bckImg.add(panel8);
		bckImg.add(panel9);
		bckImg.add(panel10);
		bckImg.add(panel11);
		bckImg.add(panel12);
		bckImg.add(panel13);
		bckImg.add(panel14);
		bckImg.add(panel15);
		bckImg.add(panel16);
		bckImg.add(panel17);
		bckImg.add(panel18);
		bckImg.add(panel19);
		bckImg.add(panel20);
		bckImg.add(panel21);
		bckImg.add(panel22);
		bckImg.add(panel23);
		bckImg.add(panel24);
		bckImg.add(panel25);
		bckImg.add(panel26);
		bckImg.add(panel27);
		bckImg.add(panel28);
		bckImg.add(panel29);
		bckImg.add(panel30);
		bckImg.add(panel31);
		bckImg.add(panel32);
		bckImg.add(panel33);
		bckImg.add(panel34);
		bckImg.add(panel35);
		bckImg.add(panel36);
		bckImg.add(panel37);
		bckImg.add(panel38);
		bckImg.add(panel39);
		bckImg.add(panel40);
		bckImg.add(panel41);
		bckImg.add(panel42);

		/**
		 * Creating date labels
		 */

		w = 130;
		h = 20;
		x = 5;
		y = 5;

		p1label = new JLabel();
		p1label.setBounds(x, y, w, h);

		p2label = new JLabel();
		p2label.setBounds(x, y, w, h);

		p3label = new JLabel();
		p3label.setBounds(x, y, w, h);

		p4label = new JLabel();
		p4label.setBounds(x, y, w, h);

		p5label = new JLabel();
		p5label.setBounds(x, y, w, h);

		p6label = new JLabel();
		p6label.setBounds(x, y, w, h);

		p7label = new JLabel();
		p7label.setBounds(x, y, w, h);

		p8label = new JLabel();
		p8label.setBounds(x, y, w, h);

		p9label = new JLabel();
		p9label.setBounds(x, y, w, h);

		p10label = new JLabel();
		p10label.setBounds(x, y, w, h);

		p11label = new JLabel();
		p11label.setBounds(x, y, w, h);

		p12label = new JLabel();
		p12label.setBounds(x, y, w, h);

		p13label = new JLabel();
		p13label.setBounds(x, y, w, h);

		p14label = new JLabel();
		p14label.setBounds(x, y, w, h);

		p15label = new JLabel();
		p15label.setBounds(x, y, w, h);

		p16label = new JLabel();
		p16label.setBounds(x, y, w, h);

		p17label = new JLabel();
		p17label.setBounds(x, y, w, h);

		p18label = new JLabel();
		p18label.setBounds(x, y, w, h);

		p19label = new JLabel();
		p19label.setBounds(x, y, w, h);

		p20label = new JLabel();
		p20label.setBounds(x, y, w, h);

		p21label = new JLabel();
		p21label.setBounds(x, y, w, h);

		p22label = new JLabel();
		p22label.setBounds(x, y, w, h);

		p23label = new JLabel();
		p23label.setBounds(x, y, w, h);

		p24label = new JLabel();
		p24label.setBounds(x, y, w, h);

		p25label = new JLabel();
		p25label.setBounds(x, y, w, h);

		p26label = new JLabel();
		p26label.setBounds(x, y, w, h);

		p27label = new JLabel();
		p27label.setBounds(x, y, w, h);

		p28label = new JLabel();
		p28label.setBounds(x, y, w, h);

		p29label = new JLabel();
		p29label.setBounds(x, y, w, h);

		p30label = new JLabel();
		p30label.setBounds(x, y, w, h);

		p31label = new JLabel();
		p31label.setBounds(x, y, w, h);

		p32label = new JLabel();
		p32label.setBounds(x, y, w, h);

		p33label = new JLabel();
		p33label.setBounds(x, y, w, h);

		p34label = new JLabel();
		p34label.setBounds(x, y, w, h);

		p35label = new JLabel();
		p35label.setBounds(x, y, w, h);

		p36label = new JLabel();
		p36label.setBounds(x, y, w, h);

		p37label = new JLabel();
		p37label.setBounds(x, y, w, h);

		p38label = new JLabel();
		p38label.setBounds(x, y, w, h);

		p39label = new JLabel();
		p39label.setBounds(x, y, w, h);

		p40label = new JLabel();
		p40label.setBounds(x, y, w, h);

		p41label = new JLabel();
		p41label.setBounds(x, y, w, h);

		p42label = new JLabel();
		p42label.setBounds(x, y, w, h);

		/*
		 * Note panels
		 */

		h = 50;
		color = "#F1F3F2";
		y = 40;
		w = 140;
		x = 0;

		notePane1 = new JPanel();
		notePane1.setBounds(x, y, w, h);
		notePane1.setBackground(Color.decode(color));
		notePane1.setLayout(null);
		notePane1.setVisible(false); // if there is no note on sql it shouldnt shown on

		notePane2 = new JPanel();
		notePane2.setBounds(x, y, w, h);
		notePane2.setBackground(Color.decode(color));
		notePane2.setLayout(null);
		notePane2.setVisible(false);

		notePane3 = new JPanel();
		notePane3.setBounds(x, y, w, h);
		notePane3.setBackground(Color.decode(color));
		notePane3.setLayout(null);
		notePane3.setVisible(false);

		notePane4 = new JPanel();
		notePane4.setBounds(x, y, w, h);
		notePane4.setBackground(Color.decode(color));
		notePane4.setLayout(null);
		notePane4.setVisible(false);

		notePane5 = new JPanel();
		notePane5.setBounds(x, y, w, h);
		notePane5.setBackground(Color.decode(color));
		notePane5.setLayout(null);
		notePane5.setVisible(false);

		notePane6 = new JPanel();
		notePane6.setBounds(x, y, w, h);
		notePane6.setBackground(Color.decode(color));
		notePane6.setLayout(null);
		notePane6.setVisible(false);

		notePane7 = new JPanel();
		notePane7.setBounds(x, y, w, h);
		notePane7.setBackground(Color.decode(color));
		notePane7.setLayout(null);
		notePane7.setVisible(false);

		notePane8 = new JPanel();
		notePane8.setBounds(x, y, w, h);
		notePane8.setBackground(Color.decode(color));
		notePane8.setLayout(null);
		notePane8.setVisible(false);

		notePane9 = new JPanel();
		notePane9.setBounds(x, y, w, h);
		notePane9.setBackground(Color.decode(color));
		notePane9.setLayout(null);
		notePane9.setVisible(false);

		notePane10 = new JPanel();
		notePane10.setBounds(x, y, w, h);
		notePane10.setBackground(Color.decode(color));
		notePane10.setLayout(null);
		notePane10.setVisible(false);

		notePane11 = new JPanel();
		notePane11.setBounds(x, y, w, h);
		notePane11.setBackground(Color.decode(color));
		notePane11.setLayout(null);
		notePane11.setVisible(false);

		notePane12 = new JPanel();
		notePane12.setBounds(x, y, w, h);
		notePane12.setBackground(Color.decode(color));
		notePane12.setLayout(null);
		notePane12.setVisible(false);

		notePane13 = new JPanel();
		notePane13.setBounds(x, y, w, h);
		notePane13.setBackground(Color.decode(color));
		notePane13.setLayout(null);
		notePane13.setVisible(false);

		notePane14 = new JPanel();
		notePane14.setBounds(x, y, w, h);
		notePane14.setBackground(Color.decode(color));
		notePane14.setLayout(null);
		notePane14.setVisible(false);

		notePane15 = new JPanel();
		notePane15.setBounds(x, y, w, h);
		notePane15.setBackground(Color.decode(color));
		notePane15.setLayout(null);
		notePane15.setVisible(false);

		notePane16 = new JPanel();
		notePane16.setBounds(x, y, w, h);
		notePane16.setBackground(Color.decode(color));
		notePane16.setLayout(null);
		notePane16.setVisible(false);

		notePane17 = new JPanel();
		notePane17.setBounds(x, y, w, h);
		notePane17.setBackground(Color.decode(color));
		notePane17.setLayout(null);
		notePane17.setVisible(false);

		notePane18 = new JPanel();
		notePane18.setBounds(x, y, w, h);
		notePane18.setBackground(Color.decode(color));
		notePane18.setLayout(null);
		notePane18.setVisible(false);

		notePane19 = new JPanel();
		notePane19.setBounds(x, y, w, h);
		notePane19.setBackground(Color.decode(color));
		notePane19.setLayout(null);
		notePane19.setVisible(false);

		notePane20 = new JPanel();
		notePane20.setBounds(x, y, w, h);
		notePane20.setBackground(Color.decode(color));
		notePane20.setLayout(null);
		notePane20.setVisible(false);

		notePane21 = new JPanel();
		notePane21.setBounds(x, y, w, h);
		notePane21.setBackground(Color.decode(color));
		notePane21.setLayout(null);
		notePane21.setVisible(false);

		notePane22 = new JPanel();
		notePane22.setBounds(x, y, w, h);
		notePane22.setBackground(Color.decode(color));
		notePane22.setLayout(null);
		notePane22.setVisible(false);

		notePane23 = new JPanel();
		notePane23.setBounds(x, y, w, h);
		notePane23.setBackground(Color.decode(color));
		notePane23.setLayout(null);
		notePane23.setVisible(false);

		notePane24 = new JPanel();
		notePane24.setBounds(x, y, w, h);
		notePane24.setBackground(Color.decode(color));
		notePane24.setLayout(null);
		notePane24.setVisible(false);

		notePane25 = new JPanel();
		notePane25.setBounds(x, y, w, h);
		notePane25.setBackground(Color.decode(color));
		notePane25.setLayout(null);
		notePane25.setVisible(false);

		notePane26 = new JPanel();
		notePane26.setBounds(x, y, w, h);
		notePane26.setBackground(Color.decode(color));
		notePane26.setLayout(null);
		notePane26.setVisible(false);

		notePane27 = new JPanel();
		notePane27.setBounds(x, y, w, h);
		notePane27.setBackground(Color.decode(color));
		notePane27.setLayout(null);
		notePane27.setVisible(false);

		notePane28 = new JPanel();
		notePane28.setBounds(x, y, w, h);
		notePane28.setBackground(Color.decode(color));
		notePane28.setLayout(null);
		notePane28.setVisible(false);

		notePane29 = new JPanel();
		notePane29.setBounds(x, y, w, h);
		notePane29.setBackground(Color.decode(color));
		notePane29.setLayout(null);
		notePane29.setVisible(false);

		notePane30 = new JPanel();
		notePane30.setBounds(x, y, w, h);
		notePane30.setBackground(Color.decode(color));
		notePane30.setLayout(null);
		notePane30.setVisible(false);

		notePane31 = new JPanel();
		notePane31.setBounds(x, y, w, h);
		notePane31.setBackground(Color.decode(color));
		notePane31.setLayout(null);
		notePane31.setVisible(false);

		notePane32 = new JPanel();
		notePane32.setBounds(x, y, w, h);
		notePane32.setBackground(Color.decode(color));
		notePane32.setLayout(null);
		notePane32.setVisible(false);

		notePane33 = new JPanel();
		notePane33.setBounds(x, y, w, h);
		notePane33.setBackground(Color.decode(color));
		notePane33.setLayout(null);
		notePane33.setVisible(false);

		notePane34 = new JPanel();
		notePane34.setBounds(x, y, w, h);
		notePane34.setBackground(Color.decode(color));
		notePane34.setLayout(null);
		notePane34.setVisible(false);

		notePane35 = new JPanel();
		notePane35.setBounds(x, y, w, h);
		notePane35.setBackground(Color.decode(color));
		notePane35.setLayout(null);
		notePane35.setVisible(false);

		notePane36 = new JPanel();
		notePane36.setBounds(x, y, w, h);
		notePane36.setBackground(Color.decode(color));
		notePane36.setLayout(null);
		notePane36.setVisible(false);

		notePane37 = new JPanel();
		notePane37.setBounds(x, y, w, h);
		notePane37.setBackground(Color.decode(color));
		notePane37.setLayout(null);
		notePane37.setVisible(false);

		notePane38 = new JPanel();
		notePane38.setBounds(x, y, w, h);
		notePane38.setBackground(Color.decode(color));
		notePane38.setLayout(null);
		notePane38.setVisible(false);

		notePane39 = new JPanel();
		notePane39.setBounds(x, y, w, h);
		notePane39.setBackground(Color.decode(color));
		notePane39.setLayout(null);
		notePane39.setVisible(false);

		notePane40 = new JPanel();
		notePane40.setBounds(x, y, w, h);
		notePane40.setBackground(Color.decode(color));
		notePane40.setLayout(null);
		notePane40.setVisible(false);

		notePane41 = new JPanel();
		notePane41.setBounds(x, y, w, h);
		notePane41.setBackground(Color.decode(color));
		notePane41.setLayout(null);
		notePane41.setVisible(false);

		notePane42 = new JPanel();
		notePane42.setBounds(x, y, w, h);
		notePane42.setBackground(Color.decode(color));
		notePane42.setLayout(null);
		notePane42.setVisible(false);

		/*
		 * Add note panel to main panels
		 */

		panel1.add(notePane1);
		panel2.add(notePane2);
		panel3.add(notePane3);
		panel4.add(notePane4);
		panel5.add(notePane5);
		panel6.add(notePane6);
		panel7.add(notePane7);
		panel8.add(notePane8);
		panel9.add(notePane9);
		panel10.add(notePane10);
		panel11.add(notePane11);
		panel12.add(notePane12);
		panel13.add(notePane13);
		panel14.add(notePane14);
		panel15.add(notePane15);
		panel16.add(notePane16);
		panel17.add(notePane17);
		panel18.add(notePane18);
		panel19.add(notePane19);
		panel20.add(notePane20);
		panel21.add(notePane21);
		panel22.add(notePane22);
		panel23.add(notePane23);
		panel24.add(notePane24);
		panel25.add(notePane25);
		panel26.add(notePane26);
		panel27.add(notePane27);
		panel28.add(notePane28);
		panel29.add(notePane29);
		panel30.add(notePane30);
		panel31.add(notePane31);
		panel32.add(notePane32);
		panel33.add(notePane33);
		panel34.add(notePane34);
		panel35.add(notePane35);
		panel36.add(notePane36);
		panel37.add(notePane37);
		panel38.add(notePane38);
		panel39.add(notePane39);
		panel40.add(notePane40);
		panel41.add(notePane41);
		panel42.add(notePane42);

		/*
		 * Note panels' labels creating
		 */
		h = 40;
		y = 5;
		w = 120;
		x = 10;

		npl1 = new JLabel();
		npl1.setBounds(x, y, w, h);

		npl2 = new JLabel();
		npl2.setBounds(x, y, w, h);

		npl3 = new JLabel();
		npl3.setBounds(x, y, w, h);

		npl4 = new JLabel();
		npl4.setBounds(x, y, w, h);

		npl5 = new JLabel();
		npl5.setBounds(x, y, w, h);

		npl6 = new JLabel();
		npl6.setBounds(x, y, w, h);

		npl7 = new JLabel();
		npl7.setBounds(x, y, w, h);

		npl8 = new JLabel();
		npl8.setBounds(x, y, w, h);

		npl9 = new JLabel();
		npl9.setBounds(x, y, w, h);

		npl10 = new JLabel();
		npl10.setBounds(x, y, w, h);

		npl11 = new JLabel();
		npl11.setBounds(x, y, w, h);

		npl12 = new JLabel();
		npl12.setBounds(x, y, w, h);

		npl13 = new JLabel();
		npl13.setBounds(x, y, w, h);

		npl14 = new JLabel();
		npl14.setBounds(x, y, w, h);

		npl15 = new JLabel();
		npl15.setBounds(x, y, w, h);

		npl16 = new JLabel();
		npl16.setBounds(x, y, w, h);

		npl17 = new JLabel();
		npl17.setBounds(x, y, w, h);

		npl18 = new JLabel();
		npl18.setBounds(x, y, w, h);

		npl19 = new JLabel();
		npl19.setBounds(x, y, w, h);

		npl20 = new JLabel();
		npl20.setBounds(x, y, w, h);

		npl21 = new JLabel();
		npl21.setBounds(x, y, w, h);

		npl22 = new JLabel();
		npl22.setBounds(x, y, w, h);

		npl23 = new JLabel();
		npl23.setBounds(x, y, w, h);

		npl24 = new JLabel();
		npl24.setBounds(x, y, w, h);

		npl25 = new JLabel();
		npl25.setBounds(x, y, w, h);

		npl26 = new JLabel();
		npl26.setBounds(x, y, w, h);

		npl27 = new JLabel();
		npl27.setBounds(x, y, w, h);

		npl28 = new JLabel();
		npl28.setBounds(x, y, w, h);

		npl29 = new JLabel();
		npl29.setBounds(x, y, w, h);

		npl30 = new JLabel();
		npl30.setBounds(x, y, w, h);

		npl31 = new JLabel();
		npl31.setBounds(x, y, w, h);

		npl32 = new JLabel();
		npl32.setBounds(x, y, w, h);

		npl33 = new JLabel();
		npl33.setBounds(x, y, w, h);

		npl34 = new JLabel();
		npl34.setBounds(x, y, w, h);

		npl35 = new JLabel();
		npl35.setBounds(x, y, w, h);

		npl36 = new JLabel();
		npl36.setBounds(x, y, w, h);

		npl37 = new JLabel();
		npl37.setBounds(x, y, w, h);

		npl38 = new JLabel();
		npl38.setBounds(x, y, w, h);

		npl39 = new JLabel();
		npl39.setBounds(x, y, w, h);

		npl40 = new JLabel();
		npl40.setBounds(x, y, w, h);

		npl41 = new JLabel();
		npl41.setBounds(x, y, w, h);

		npl42 = new JLabel();
		npl42.setBounds(x, y, w, h);

		/*
		 * Add note labels to note panels
		 */

		notePane1.add(npl1);
		notePane2.add(npl2);
		notePane3.add(npl3);
		notePane4.add(npl4);
		notePane5.add(npl5);
		notePane6.add(npl6);
		notePane7.add(npl7);
		notePane8.add(npl8);
		notePane9.add(npl9);
		notePane10.add(npl10);
		notePane11.add(npl11);
		notePane12.add(npl12);
		notePane13.add(npl13);
		notePane14.add(npl14);
		notePane15.add(npl15);
		notePane16.add(npl16);
		notePane17.add(npl17);
		notePane18.add(npl18);
		notePane19.add(npl19);
		notePane20.add(npl20);
		notePane21.add(npl21);
		notePane22.add(npl22);
		notePane23.add(npl23);
		notePane24.add(npl24);
		notePane25.add(npl25);
		notePane26.add(npl26);
		notePane27.add(npl27);
		notePane28.add(npl28);
		notePane29.add(npl29);
		notePane30.add(npl30);
		notePane31.add(npl31);
		notePane32.add(npl32);
		notePane33.add(npl33);
		notePane34.add(npl34);
		notePane35.add(npl35);
		notePane36.add(npl36);
		notePane37.add(npl37);
		notePane38.add(npl38);
		notePane39.add(npl39);
		notePane40.add(npl40);
		notePane41.add(npl41);
		notePane42.add(npl42);

		/**
		 * LittleCalendar Class
		 */

		LittleCalendar littleCalendar = new LittleCalendar();
		littleCalendar.setSize(385, 250);
		littleCalendar.setLocation(940, 5);
		bckImg.add(littleCalendar);
		littleCalendar.setLayout(null);

		// note area layout
		p = new JPanel();
		p.setBounds(941, 260, 300, 390);
		p.setBackground(Color.decode("#FFFF88")); // note area color
		p.setVisible(true);
		p.setLayout(null);
		bckImg.add(p);

		// note enter area
		message = new JTextArea("Click add note button and take note!");
		message.setBounds(10, 74, 240, 270);
		p.add(message);
		message.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				if (thr == true)
					message.setText("");
			}
		});
		message.setFont(new Font("Times New Roman", Font.PLAIN, 16));
		message.setBackground(Color.decode("#FFFF88"));
		message.setEditable(false);

		JSeparator separator = new JSeparator();
		separator.setBounds(0, 61, 300, 2);
		p.add(separator);

		JLabel lblNotes = new JLabel("NOTES");
		lblNotes.setFont(new Font("Roboto", Font.BOLD, 30));
		lblNotes.setBounds(10, 11, 123, 39);
		p.add(lblNotes);
		// buttons
		save = new JButton();
		save.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				save.setVisible(false); // after clicking save button it wont visible
				cancel.setVisible(false);
				message.setEditable(false);
				message.selectAll();
				if (add == true) {
					if (Sql.day == 0) {
						JOptionPane.showMessageDialog(null, "You did not select a day from calendar!"); // if you don't
																										// select a day
																										// on little
																										// calendar it
																										// wont add note
					} else {
						String note = message.getSelectedText();
						if (note == null)
							note = "";
						Sql.addNote(note);
					}
				}
				add = false;
				if (edit == true) {
					if (Sql.day == 0) {
						JOptionPane.showMessageDialog(null, "You did not select a day from calendar!");
					} else {
						message.selectAll();
						String note = message.getSelectedText();

						if (note == null)
							note = "";
						Sql.editNote(note, oldMessage);
					}
				}
				edit = false;
				if (delete == true)
					Sql.deleteNote(slcDay, slcMonth, slcYear);
				delete = false;
				thr = false;
				LittleCalendar.setDay(LittleCalendar.dayOfWeek, LittleCalendar.maxDay);
			}
		});
		save.setBounds(0, 355, 150, 35);
		save.setBackground(Color.decode("#5cb85c"));
		p.add(save);
		save.setVisible(false);
		save.setIcon(new ImageIcon("./icon/ok-mark.png"));

		cancel = new JButton();
		cancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				save.setVisible(false);
				cancel.setVisible(false);
				message.setEditable(false);
				thr = false;
			}
		});
		cancel.setBounds(150, 355, 150, 35);
		cancel.setBackground(Color.decode("#d9534f"));
		p.add(cancel);
		cancel.setVisible(false);
		cancel.setIcon(new ImageIcon("./icon/cross.png"));

		addBtn = new JButton("Add");
		addBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				save.setVisible(true);
				cancel.setVisible(true);
				if (situation == false)
					message.setText("Write here...");
				message.setEditable(true);
				message.selectAll();
				thr = true;
				add = true;
			}
		});
		addBtn.setBounds(1245, 530, 80, 25);
		bckImg.add(addBtn);
		addBtn.setBackground(Color.decode("#2ECC71"));

		/*
		 * weather condition panel
		 */

		JPanel weatherPanel = new JPanel();
		weatherPanel.setLayout(null);
		weatherPanel.setSize(85, 100);
		weatherPanel.setLocation(1240, 260);
		weatherPanel.setBackground(Color.decode("#F1F3F2"));

		JTextPane weatherTxt = new JTextPane();
		weatherTxt.setBounds(15, 60, 56, 130);
		weatherTxt.setBackground(Color.decode("#F1F3F2"));
		weatherTxt.setFont(new Font("Montserrat", Font.PLAIN, 15));
		weatherPanel.add(weatherTxt);

		JLabel panel = new JLabel();
		panel.setBounds(10, 11, 96, 44);
		weatherPanel.add(panel);
		panel.setLayout(null);

		String url = null;
		String degree = null;

		try {
			Document doc = Jsoup.connect(
					"https://www.google.com.tr/search?client=opera&q=adana+hava+durumu%2C&sourceid=opera&ie=UTF-8&oe=UTF-8")
					.get();
			Elements temp = doc.select("div.vk_bk");
			int i = 0;
			for (Element degrees : temp) {
				degree += " " + degrees.getElementsByTag("span").first().text();
				degree = degree.substring(2);
			}
			Elements img = doc.select("div#wob_d");
			i = 0;

			for (Element imgs : img) {
				if (imgs.getElementsByTag("img").attr("src").startsWith("//ssl"))
					url = "http:" + imgs.getElementsByTag("img").attr("src");
			}
			URL urlNew = new URL(url);
			Image image = ImageIO.read(urlNew);
			JLabel lbl = new JLabel();
			lbl.setLayout(null);
			lbl.setBounds(10, 0, 60, 60);
			lbl.setIcon(new ImageIcon(image.getScaledInstance(60, 60, Image.SCALE_SMOOTH)));
			weatherPanel.add(lbl);

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		weatherTxt.setText(degree);
		bckImg.add(weatherPanel);

		// ****************************

		

		editBtn = new JButton("Edit");
		editBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				save.setVisible(true);
				cancel.setVisible(true);
				message.setEditable(true);
				edit = true;
				message.selectAll();
				oldMessage = message.getSelectedText();
			}
		});
		editBtn.setBounds(1245, 560, 80, 25);
		bckImg.add(editBtn);
		editBtn.setBackground(Color.decode("#3498DB"));

		deleteBtn = new JButton("Delete");
		deleteBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				save.setVisible(true);
				cancel.setVisible(true);
				delete = true;
			}
		});
		deleteBtn.setBounds(1245, 590, 80, 25);
		bckImg.add(deleteBtn);
		deleteBtn.setBackground(Color.decode("#E74C3C"));

		System.gc();
	}
}
