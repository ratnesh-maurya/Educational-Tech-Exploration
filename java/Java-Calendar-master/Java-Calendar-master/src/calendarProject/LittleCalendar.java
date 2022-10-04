package calendarProject;

import javax.swing.JPanel;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import javax.swing.ListSelectionModel;
import java.awt.Color;
import java.awt.ComponentOrientation;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.GregorianCalendar;
import javax.swing.SwingConstants;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.border.SoftBevelBorder;
import javax.swing.border.BevelBorder;
import java.util.Timer;
import java.util.TimerTask;

public class LittleCalendar extends JPanel {

	private JButton leftBtn, rightBtn;
	private JTable table;
	private JPanel timeArea;
	private JLabel monthDay;
	private JComboBox monthList, yearList;
	private String[] dayName = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	private Integer[] days = new Integer[42];
	public static int year, month, dayOfWeek, hourOfDay, minute, maxDay, thisDay;
	private int selectedRow, selectedColumn, newSelectedRow = 1, newSelectedColumn = 0;
	private static String[] months = { "January", "Fabruary", "March", "April", "May", "June", "July", "August",
			"September", "October", "November", "December" };
	public static JPanel[][] panels = {

			{ Calendar.panel1, Calendar.panel2, Calendar.panel3, Calendar.panel4, Calendar.panel5, Calendar.panel6,
					Calendar.panel7 },
			{ Calendar.panel8, Calendar.panel9, Calendar.panel10, Calendar.panel11, Calendar.panel12, Calendar.panel13,
					Calendar.panel14 },
			{ Calendar.panel15, Calendar.panel16, Calendar.panel17, Calendar.panel18, Calendar.panel19,
					Calendar.panel20, Calendar.panel21 },
			{ Calendar.panel22, Calendar.panel23, Calendar.panel24, Calendar.panel25, Calendar.panel26,
					Calendar.panel27, Calendar.panel28 },
			{ Calendar.panel29, Calendar.panel30, Calendar.panel31, Calendar.panel32, Calendar.panel33,
					Calendar.panel34, Calendar.panel35 },
			{ Calendar.panel36, Calendar.panel37, Calendar.panel38, Calendar.panel39, Calendar.panel40,
					Calendar.panel41, Calendar.panel42 } };
	public static JPanel[] notePanels = { Calendar.notePane1, Calendar.notePane2, Calendar.notePane3,
			Calendar.notePane4, Calendar.notePane5, Calendar.notePane6, Calendar.notePane7, Calendar.notePane8,
			Calendar.notePane9, Calendar.notePane10, Calendar.notePane11, Calendar.notePane12, Calendar.notePane13,
			Calendar.notePane14, Calendar.notePane15, Calendar.notePane16, Calendar.notePane17, Calendar.notePane18,
			Calendar.notePane19, Calendar.notePane20, Calendar.notePane21, Calendar.notePane22, Calendar.notePane23,
			Calendar.notePane24, Calendar.notePane25, Calendar.notePane26, Calendar.notePane27, Calendar.notePane28,
			Calendar.notePane29, Calendar.notePane30, Calendar.notePane31, Calendar.notePane32, Calendar.notePane33,
			Calendar.notePane34, Calendar.notePane35, Calendar.notePane36, Calendar.notePane37, Calendar.notePane38,
			Calendar.notePane39, Calendar.notePane40, Calendar.notePane41, Calendar.notePane42 };
	public static JLabel[] labels = { Calendar.p1label, Calendar.p2label, Calendar.p3label, Calendar.p4label,
			Calendar.p5label, Calendar.p6label, Calendar.p7label, Calendar.p8label, Calendar.p9label, Calendar.p10label,
			Calendar.p11label, Calendar.p12label, Calendar.p13label, Calendar.p14label, Calendar.p15label,
			Calendar.p16label, Calendar.p17label, Calendar.p18label, Calendar.p19label, Calendar.p20label,
			Calendar.p21label, Calendar.p22label, Calendar.p23label, Calendar.p24label, Calendar.p25label,
			Calendar.p26label, Calendar.p27label, Calendar.p28label, Calendar.p29label, Calendar.p30label,
			Calendar.p31label, Calendar.p32label, Calendar.p33label, Calendar.p34label, Calendar.p35label,
			Calendar.p36label, Calendar.p37label, Calendar.p38label, Calendar.p39label, Calendar.p40label,
			Calendar.p41label, Calendar.p42label };
	public static JLabel[] nplabels = { Calendar.npl1, Calendar.npl2, Calendar.npl3, Calendar.npl4, Calendar.npl5,
			Calendar.npl6, Calendar.npl7, Calendar.npl8, Calendar.npl9, Calendar.npl10, Calendar.npl11, Calendar.npl12,
			Calendar.npl13, Calendar.npl14, Calendar.npl15, Calendar.npl16, Calendar.npl17, Calendar.npl18,
			Calendar.npl19, Calendar.npl20, Calendar.npl21, Calendar.npl22, Calendar.npl23, Calendar.npl24,
			Calendar.npl25, Calendar.npl26, Calendar.npl27, Calendar.npl28, Calendar.npl29, Calendar.npl30,
			Calendar.npl31, Calendar.npl32, Calendar.npl33, Calendar.npl34, Calendar.npl35, Calendar.npl36,
			Calendar.npl37, Calendar.npl38, Calendar.npl39, Calendar.npl40, Calendar.npl41, Calendar.npl42 };
	private String note = "undf";
	public static JLabel lable;
	public static JPanel pdeneme;
	public static int dayweek;
	public boolean isCurrentDay = false;

	/**
	 * Create the panel.
	 */
	public LittleCalendar() {

		setLayout(null);
		setBackground(new Color(41, 40, 38));
		GregorianCalendar times = new GregorianCalendar();
		year = times.get(times.YEAR);
		month = times.get(times.MONTH);
		thisDay = times.get(times.DATE);
		hourOfDay = times.get(times.HOUR_OF_DAY); // 24 hour clock
		minute = times.get(times.MINUTE);
		maxDay = times.getActualMaximum(times.DAY_OF_MONTH);
		dayweek = times.get(times.DAY_OF_WEEK);

		monthDay = new JLabel(months[month] + " " + year);
		monthDay.setForeground(Color.decode("#F1F3F2"));
		monthDay.setHorizontalAlignment(SwingConstants.CENTER);// put the date at center
		monthDay.setBounds(95, 7, 70, 30);
		add(monthDay);

		times.set(year, month, 1); // set first day to get the months starting day
		dayOfWeek = times.get(times.DAY_OF_WEEK);
		setDay(dayOfWeek, maxDay);

		table = new JTable();
		table.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
		table.setAutoCreateRowSorter(true);
		table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		table.setColumnSelectionAllowed(true);
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		table.setModel(new DefaultTableModel(
				new Object[][] { { " Sun", " Mon", " Tue", " Wed", " Thu", " Fri", " Sat" },
						{ days[0], days[1], days[2], days[3], days[4], days[5], days[6] },
						{ days[7], days[8], days[9], days[10], days[11], days[12], days[13] },
						{ days[14], days[15], days[16], days[17], days[18], days[19], days[20] },
						{ days[21], days[22], days[23], days[24], days[25], days[26], days[27] },
						{ days[28], days[29], days[30], days[31], days[32], days[33], days[34] },
						{ days[35], days[36], days[37], days[38], days[39], days[40], days[41] } },
				new String[] { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" }) {
			boolean[] columnEditables = new boolean[] { true, true, true, true, true, true, true };

			public boolean isCellEditable(int row, int column) {
				return columnEditables[column];
			}
		});
		table.getColumnModel().getColumn(0).setResizable(false);
		table.getColumnModel().getColumn(0).setPreferredWidth(27);
		table.getColumnModel().getColumn(1).setResizable(false);
		table.getColumnModel().getColumn(1).setPreferredWidth(27);
		table.getColumnModel().getColumn(2).setResizable(false);
		table.getColumnModel().getColumn(2).setPreferredWidth(27);
		table.getColumnModel().getColumn(3).setResizable(false);
		table.getColumnModel().getColumn(3).setPreferredWidth(27);
		table.getColumnModel().getColumn(4).setResizable(false);
		table.getColumnModel().getColumn(4).setPreferredWidth(27);
		table.getColumnModel().getColumn(5).setResizable(false);
		table.getColumnModel().getColumn(5).setPreferredWidth(27);
		table.getColumnModel().getColumn(6).setResizable(false);
		table.getColumnModel().getColumn(6).setPreferredWidth(27);
		table.setRowHeight(24);
		table.setCellSelectionEnabled(true);
		table.setBounds(10, 48, 255, 169);
		add(table);
		setLittleDay(times.get(times.DAY_OF_WEEK), maxDay);

		table.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				selectedColumn = table.getSelectedColumn();
				selectedRow = table.getSelectedRow();
				if (isCurrentDay == true) {
					panels[newSelectedRow - 1][newSelectedColumn].setBackground(Color.decode("#81A3A7"));
					isCurrentDay = false;
				} else {
					panels[newSelectedRow - 1][newSelectedColumn].setBackground(new Color(41, 40, 38));
				}
				if (selectedRow != 0) {// to ignore row that carries the name of week
					if (panels[selectedRow - 1][selectedColumn].getBackground().equals(new Color(129, 163, 167))) {
						isCurrentDay = true;
					}
					panels[selectedRow - 1][selectedColumn].setBackground(Color.decode("#585A56")); // paint selected
																									// panel
					newSelectedRow = selectedRow;
					newSelectedColumn = selectedColumn;
				}
				try {
					sendSql(selectedRow, selectedColumn, times.get(times.DAY_OF_WEEK));
				} catch (Exception e2) {
					// do nothing in catch
				}
				if (Calendar.situation == false)
					Calendar.message.setText("Click add note button and take note!");
			}
		});

		leftBtn = new JButton();
		leftBtn.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				if (month == 0) {
					month = 11;
					year--;
				}
				times.set(year, --month, 1);
				year = times.get(times.YEAR);
				monthDay.setText(months[month] + " " + year);
				maxDay = times.getActualMaximum(times.DAY_OF_MONTH);
				monthList.setSelectedIndex(month);
				yearList.setSelectedIndex(year - 1996);
				setLittleDay(times.get(times.DAY_OF_WEEK), maxDay);
				dayOfWeek = times.get(times.DAY_OF_WEEK);
				setDay(dayOfWeek, maxDay);
			}
		});
		leftBtn.setBounds(10, 10, 55, 25);
		add(leftBtn);
		leftBtn.setIcon(new ImageIcon("./icon/left-arrows.png"));

		rightBtn = new JButton();
		rightBtn.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				if (month == 11) {
					month = 0;
					year++;
				}
				times.set(year, ++month, 1);
				year = times.get(times.YEAR);
				monthDay.setText(months[month] + " " + year);
				maxDay = times.getActualMaximum(times.DAY_OF_MONTH);
				monthList.setSelectedIndex(month);
				yearList.setSelectedIndex(year - 1996);
				setLittleDay(times.get(times.DAY_OF_WEEK), maxDay);
				dayOfWeek = times.get(times.DAY_OF_WEEK);
				setDay(dayOfWeek, maxDay);
			}
		});

		rightBtn.setBounds(210, 10, 55, 25);
		rightBtn.setIcon(new ImageIcon("./icon/right-arrows.png"));
		add(rightBtn);

		int[] years = { 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011,
				2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024 };
		yearList = new JComboBox();
		yearList.setModel(new DefaultComboBoxModel(new String[] { "1996", "1997", "1998", "1999", "2000", "2001",
				"2002", "2003", "2004", "2005", "2006", "2007", "2008", "2009", "2010", "2011", "2012", "2013", "2014",
				"2015", "2016", "2017", "2018", "2019", "2020", "2021", "2022", "2023", "2024" }));
		yearList.setSelectedIndex(year - 1996);
		yearList.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				times.set(years[yearList.getSelectedIndex()], month, 1);
				year = times.get(times.YEAR);
				month = times.get(times.MONTH);
				monthDay.setText(months[month] + " " + year);
				maxDay = times.getActualMaximum(times.DAY_OF_MONTH);
				dayOfWeek = times.get(times.DAY_OF_WEEK);
				setDay(dayOfWeek, maxDay, year, month);
				setLittleDay(dayOfWeek, maxDay);
			}
		});
		yearList.setBounds(190, 220, 65, 20);
		add(yearList);

		monthList = new JComboBox();
		monthList.setModel(new DefaultComboBoxModel(new String[] { "January", "Fabruary", "March", "April", "May",
				"June", "July", "August", "September", "October", "November", "December" }));
		monthList.setSelectedIndex(times.get(times.MONTH));
		monthList.setBounds(100, 220, 84, 20);
		monthList.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				times.set(year, monthList.getSelectedIndex(), 1);
				year = times.get(times.YEAR);
				month = times.get(times.MONTH);
				monthDay.setText(months[month] + " " + year);
				maxDay = times.getActualMaximum(times.DAY_OF_MONTH);
				dayOfWeek = times.get(times.DAY_OF_WEEK);
				setDay(dayOfWeek, maxDay, year, month);
				setLittleDay(dayOfWeek, maxDay);
			}
		});
		add(monthList);

		timeArea = new JPanel();
		timeArea.setBorder(new SoftBevelBorder(BevelBorder.RAISED, null, null, null, null));
		timeArea.setLocation(280, 7);
		timeArea.setBackground(Color.decode("#F1F3F2"));

		timeArea.setSize(100, 240);
		add(timeArea);

		JLabel clock = new JLabel();
		clock.setLocation(0, 15);
		clock.setSize(100, 40);
		clock.setHorizontalAlignment(SwingConstants.CENTER);

		JLabel secondLabel = new JLabel();
		secondLabel.setHorizontalAlignment(SwingConstants.CENTER);
		secondLabel.setLocation(0, 50);
		secondLabel.setSize(100, 60);

		JLabel weekday = new JLabel();
		weekday.setHorizontalAlignment(SwingConstants.CENTER);
		weekday.setLocation(0, 140);
		weekday.setSize(100, 60);

		JLabel calendar = new JLabel();
		calendar.setHorizontalAlignment(SwingConstants.CENTER);
		calendar.setLocation(0, 180);
		calendar.setSize(100, 60);

		timeArea.add(clock);
		timeArea.add(calendar);
		timeArea.add(weekday);
		timeArea.add(secondLabel);
		timeArea.setLayout(null);

		Timer tmer = new Timer();
		TimerTask task = new TimerTask() {

			public void run() {
				GregorianCalendar currentTime = new GregorianCalendar();
				int year = currentTime.get(currentTime.YEAR);
				String month = months[currentTime.get(currentTime.MONTH)];
				int day = currentTime.get(currentTime.DATE);
				int hour = currentTime.get(currentTime.HOUR_OF_DAY);
				int minute = currentTime.get(currentTime.MINUTE);
				int second = currentTime.get(currentTime.SECOND);
				String weekDay = dayName[currentTime.get(currentTime.DAY_OF_WEEK) - 1];
				String strHour = "" + hour;
				String strMinute = "" + minute;
				String strSecond = "" + second;

				if (hour < 10)
					strHour = "0" + hour;
				if (minute < 10)
					strMinute = "0" + minute;
				if (second < 10)
					strSecond = "0" + second;

				clock.setFont(new Font("Verdana", Font.PLAIN, 18));
				clock.setText(strHour + " : " + strMinute);

				calendar.setText(month + " " + day + " " + year);
				calendar.setFont(new Font("Verdana", Font.PLAIN, 12));

				weekday.setText(weekDay.toUpperCase());
				weekday.setFont(new Font("Verdana", Font.BOLD, 13));

				secondLabel.setText(strSecond);
				secondLabel.setFont(new Font("Verdana", Font.BOLD, 30));

			}
		};
		tmer.schedule(task, 0, 1000); // 1000 milisecond = 1 sn
		System.gc();

	}

	public static void setDay(int dayOfWeek, int maxDay) { // work only at start
		int panel = 0;
		for (int a = 0; a < dayOfWeek; a++) { // clear unused panels' labels
			labels[a].setText("");
		}
		for (int a = 41; a > maxDay - 1; a--) { // clear unused panels' labels
			labels[a].setText("");
		}

		int day = 1;
		for (int a = dayOfWeek - 1; a < maxDay + dayOfWeek - 1; a++) {
			labels[a].setFont(new Font("Verdana", Font.PLAIN, 10));
			labels[a].setHorizontalAlignment(SwingConstants.CENTER);
			if (day == thisDay)
				panel = a; // get current day
			String note = Sql.showOnPanel(day, months[month], year);
			if (note != null) {
				nplabels[a].setText(note);
				nplabels[a].setFont(new Font("Verdana", Font.PLAIN, 10));
				notePanels[a].setVisible(true);
			} else {
				notePanels[a].setVisible(false);
			}
			labels[a].setForeground(Color.decode("#F1F3F2"));
			labels[a].setText((day++) + " " + months[month] + " " + year); // set date to labels

		}
		int l = 0;
		GregorianCalendar cal = new GregorianCalendar();
		int currentMnth = cal.get(cal.MONTH);
		int currentYear = cal.get(cal.YEAR);
		for (int r = 0; r < 6; r++) { // put labels to panels
			for (int c = 0; c < 7; c++) {
				if (l == panel && month == currentMnth && year == currentYear) // paint current day's panel
					panels[r][c].setBackground(Color.decode("#81A3A7"));
				else {
					panels[r][c].setBackground(new Color(41, 40, 38));
				}
				panels[r][c].add(labels[l++]);
			}
		}

	}

	public void setDay(int dayOfWeek, int maxDay, int year, int month) {
		int panel = 0;
		for (int a = 41; a > maxDay - 1; a--) { // clear unused panels' labels
			labels[a].setText("");
		}
		for (int a = 0; a < dayOfWeek; a++) { // clear unused panels' labels
			labels[a].setText("");
		}
		int day = 1;
		for (int a = dayOfWeek - 1; a < maxDay + dayOfWeek - 1; a++) {
			labels[a].setFont(new Font("Verdana", Font.PLAIN, 10));
			labels[a].setHorizontalAlignment(SwingConstants.CENTER);
			if (day == thisDay)
				panel = a;
			String note = Sql.showOnPanel(day, months[month], year);
			if (note != null) {
				nplabels[a].setText(note);
				nplabels[a].setFont(new Font("Verdana", Font.PLAIN, 10));
				notePanels[a].setVisible(true);
			} else {
				notePanels[a].setVisible(false);
			}
			labels[a].setForeground(Color.decode("#F1F3F2"));
			labels[a].setText((day++) + " " + months[month] + " " + year);
		}
		int l = 0;
		GregorianCalendar cal = new GregorianCalendar();
		int currentMnth = cal.get(cal.MONTH);
		int currentYear = cal.get(cal.YEAR);
		for (int r = 0; r < 6; r++) { // put labels to panels
			for (int c = 0; c < 7; c++) {
				if (l == panel && month == currentMnth && year == currentYear)
					panels[r][c].setBackground(Color.decode("#81A3A7"));
				else {
					panels[r][c].setBackground(new Color(41, 40, 38));
				}
				panels[r][c].add(labels[l++]);
			}

		}
	}

	public void setLittleDay(int dayOfWeek, int maxDay) {// set day of little calendar
		int day = 1;
		for (int a = dayOfWeek - 1; a < maxDay + dayOfWeek - 1; a++) {
			days[a] = day++;
		}
		for (int a = 0; a < dayOfWeek - 1; a++) {
			days[a] = null;
		}
		for (int a = 41; a > maxDay + dayOfWeek - 2; a--) {
			days[a] = null;
		}

		table.setModel(new DefaultTableModel(
				new Object[][] { { " Sun", " Mon", " Tue", " Wed", " Thu", " Fri", " Sat" },
						{ days[0], days[1], days[2], days[3], days[4], days[5], days[6] },
						{ days[7], days[8], days[9], days[10], days[11], days[12], days[13] },
						{ days[14], days[15], days[16], days[17], days[18], days[19], days[20] },
						{ days[21], days[22], days[23], days[24], days[25], days[26], days[27] },
						{ days[28], days[29], days[30], days[31], days[32], days[33], days[34] },
						{ days[35], days[36], days[37], days[38], days[39], days[40], days[41] } },
				new String[] { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" }) {
			boolean[] columnEditables = new boolean[] { false, false, false, false, false, false, false };

			public boolean isCellEditable(int row, int column) {
				return columnEditables[column];
			}
		});
	}

	public static void sendSql(int selectedRow, int selectedColumn, int dayOfWeek) {
		int labelNumber = 0;

		labelNumber = (selectedRow * 7) + selectedColumn;
		String day = labels[labelNumber - 7].getText();
		String[] splited = day.split("\\s+");

		int selectedDay = Integer.parseInt(splited[0]);
		Sql.day = selectedDay;
		String selectedMonth = splited[1];
		Sql.month = selectedMonth;
		int selectedYear = Integer.parseInt(splited[2]);
		Sql.year = selectedYear;

		Calendar.slcDay = selectedDay;
		Calendar.slcYear = selectedYear;
		Calendar.slcMonth = selectedMonth;

		Sql.showNote(selectedDay, selectedMonth, selectedYear);
	}
}
