package calendarProject;

import java.sql.*;
import javax.swing.JOptionPane;

public class Sql {
	static final String DB_URL = "jdbc:mysql://localhost:3306/sys?useUnicode=true&useLegacyDatetimeCode=false&serverTimezone=Turkey";
	static final String USER = "root";
	static final String PASS = "Emgbvks!1402.";//495693
	public static int day = 0;
	public static int year = 0;
	public static String month = "undefined";

	public static void addNote(String note) {
		if (showOnPanel(day, month, year) != null) {
			JOptionPane.showMessageDialog(null, "You have a note for this day! You can edit it only.");
		} else {
			String addNote = "insert into notes values(" + day + ",\'" + month + "\'," + year + ",\'" + note + "\')";
			Connection conn = null;
			Statement stmt = null;
			try {

				conn = DriverManager.getConnection(DB_URL, USER, PASS);
				stmt = conn.createStatement();
				int rs = stmt.executeUpdate(addNote);

			} catch (SQLException se) {
				// Handle errors for JDBC
				se.printStackTrace();
				JOptionPane.showMessageDialog(null, "not connected");
			}
			try {
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}

	public static void showNote(int day, String month, int year) {
		Connection conn = null;
		Statement stmt = null;
		try {

			conn = DriverManager.getConnection(DB_URL, USER, PASS);
			stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery(
					"select Note from notes where day = " + day + " AND month = \'" + month + "\' AND year = " + year);
			String note = "";
			while (rs.next()) {

				note += rs.getString("note");
			}
			if (note.equals("")) {
				Calendar.situation = false;
			} else {
				Calendar.situation = true;
				Calendar.message.setText(note);
			}

		} catch (SQLException se) {
			// Handle errors for JDBC
			se.printStackTrace();
			JOptionPane.showMessageDialog(null, "not connected");
		}
		try {
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public static String showOnPanel(int day, String month, int year) {
		Connection conn = null;
		Statement stmt = null;
		try {

			conn = DriverManager.getConnection(DB_URL, USER, PASS);
			stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery(
					"select Note from notes where day = " + day + " AND month = \'" + month + "\' AND year = " + year);
			String note = null;
			while (rs.next()) {
				note += rs.getString("note");
				note = note.substring(4); //trace 'null' word
			}
			if (note != null) { //if there is a note
				return note;
			}

		} catch (SQLException se) {
			// Handle errors for JDBC
			se.printStackTrace();
			JOptionPane.showMessageDialog(null, "not connected");
		}

		try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;

	}

	public static void deleteNote(int day, String month, int year) {
		Connection conn = null;
		Statement stmt = null;
		try {

			conn = DriverManager.getConnection(DB_URL, USER, PASS);
			stmt = conn.createStatement();
			boolean rs = stmt.execute(
					"delete from notes where day = " + day + " AND month = \'" + month + "\' AND year = " + year);
			JOptionPane.showMessageDialog(null, "note was deleted!");
			Calendar.message.setText("Click add new button to add a note!");

		} catch (SQLException se) {
			// Handle errors for JDBC
			se.printStackTrace();
			JOptionPane.showMessageDialog(null, "Oops! There is a problem.");
		}
		try {
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void editNote(String note, String old) {
		String editNote = "UPDATE notes set note =\'" + note + "\' where note =\'" + old + "\'";
		Connection conn = null;
		Statement stmt = null;
		try {

			conn = DriverManager.getConnection(DB_URL, USER, PASS);
			stmt = conn.createStatement();
			int rs = stmt.executeUpdate(editNote);

		} catch (SQLException se) {
			// Handle errors for JDBC
			se.printStackTrace();
			JOptionPane.showMessageDialog(null, "not connected");
		}
		try {
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}// end JDBCExample
