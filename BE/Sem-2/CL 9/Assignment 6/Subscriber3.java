package pubsub1;

import java.io.IOException;
import javax.jms.*;
import org.apache.activemq.ActiveMQConnection;
import org.apache.activemq.ActiveMQConnectionFactory;

public class Subscriber3 {
// URL of the JMS server
	private static String url = ActiveMQConnection.DEFAULT_BROKER_URL;

// Name of the topic from which we will receive messages from = " CL9"
	public static void main(String[] args) throws JMSException {
// Getting JMS connection from the server
		ConnectionFactory connectionFactory2 = new ActiveMQConnectionFactory(url);
		Connection connection2 = connectionFactory2.createConnection();
		connection2.start();
		Session session2 = connection2.createSession(false, Session.AUTO_ACKNOWLEDGE);
		Topic topic2 = session2.createTopic("IOT_Lab");
		MessageConsumer consumer2 = session2.createConsumer(topic2);
		MessageListener listner2 = new MessageListener() {
			public void onMessage(Message message) {
				try {
					if (message instanceof TextMessage) {
						TextMessage textMessage = (TextMessage) message;
						System.out.println("Received message" + textMessage.getText() + "'");
					}
				} catch (JMSException e) {
					System.out.println("Caught:" + e);
					e.printStackTrace();
				}
			}
		};
		consumer2.setMessageListener(listner2);
		try {
			System.in.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		connection2.close();
	}
}