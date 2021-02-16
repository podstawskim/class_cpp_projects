#include "Universe.h"
#include "TestIncludes.h"
#include "ObserverMock.h"
#include "TimeMock.h"
#include "SpaceMock.h"

std::string receive() { return ""; }
void send(const std::string& message) {}

class Socket {
public:

    virtual ~Socket() = default;

    virtual std::string receive() const = 0;
    virtual void send(const std::string& message) = 0;
};

class SocketImpl : public Socket {
public:

    std::string receive() const override {
        return ::receive();
    }

    void send(const std::string& message) override {
        ::send(message);
    }
};

class SocketMock : public Socket {
public:

    MOCK_CONST_METHOD0(receive, std::string());
    MOCK_METHOD1(send, void(const std::string& message));
};

class Server {
public:

    explicit Server(Socket &socket) : socket(socket) {}

    void run() {

        auto request = socket.receive();

        auto response = "Hello " + request;

        socket.send(response);
    }

private:
    Socket& socket;
};

TEST(Server, ReceiveAndSend) {

    StrictMock<SocketMock> socket{};
    Server server{socket};

    EXPECT_CALL(socket, receive()).WillOnce(Return("Tom"));
    EXPECT_CALL(socket, send("Hello Tom"));

    server.run();
}


TEST(Universe, Create)
{
    StrictMock<SpaceMock> space{};
    StrictMock<TimeMock> time{};
    StrictMock<ObserverMock> observer{};

    Universe universe{time, space, observer};

    EXPECT_CALL(time, create(true)).Times(AtLeast(1));
    EXPECT_CALL(space, create(11)).Times(AtLeast(1));
    EXPECT_CALL(space, dimensions()).WillOnce(Return(0));
    EXPECT_CALL(observer, remember("How many dimensions there are?", std::to_string(0))).Times(AtLeast(1));


    universe.create();
}

TEST(Universe, SimulateEarthExistence) {
    StrictMock<SpaceMock> space{};
    StrictMock<TimeMock> time{};
    StrictMock<ObserverMock> observer{};

    Universe universe{time, space, observer};

    EXPECT_CALL(time, now()).WillOnce(Return(9300000000)).WillOnce(Return(9300000001));
    EXPECT_CALL(observer, remember("Is there planet Earth?", "Yes!")).Times(1);
    EXPECT_CALL(time, flow()).Times(1);
    universe.simulate(9300000001);
}

TEST(Universe, SimulateLifeExistence) {
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};
    Universe universe(time, space, observer);

    EXPECT_CALL(time, now()).WillOnce(Return(9900000000)).WillOnce(Return(9900000001));
    EXPECT_CALL(observer,remember("Does life exist?", "Yes!")).Times(1);
    EXPECT_CALL(time, flow()).Times(1);

    universe.simulate(9900000001);
}

TEST(Universe, SimulatePeopleEvolution) {
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};

    Universe universe(time, space, observer);

    EXPECT_CALL(time, now()).WillOnce(Return(13800000000)).WillOnce(Return(13800000001));
    EXPECT_CALL(observer, remember("Have People evolved?", "Yes!")).Times(1);
    EXPECT_CALL(time, flow()).Times(1);

    universe.simulate(13800000001);
}

TEST(Universe, UniverseConstructor) {
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};

    Universe universe(time, space, observer);

}