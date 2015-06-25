#include "gtest/gtest.h"

#include "mesos/mesos.hpp"

#include "observers/slack_resource.hpp"

#include "tests/common/sources/json_source.hpp"

#include "tests/common/sinks/dummy_sink.hpp"

namespace mesos {
namespace serenity {
namespace tests {

TEST(SlackResourceObserver, BasicTest) {
  SlackResourceObserver observer;
  JsonSource jsonSource;
  DummySink<Resource> dummySink;

  jsonSource.addConsumer(&observer);
  observer.addConsumer(&dummySink);

  jsonSource.RunTests("tests/fixtures/json_source_test.json");

  ASSERT_EQ(dummySink.numberOfMessagesConsumed, 3);
}

}  //  namespace tests
}  //  namespace serenity
}  //  namespace mesos
