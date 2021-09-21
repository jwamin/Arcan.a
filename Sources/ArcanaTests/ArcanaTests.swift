import XCTest
@testable import Arcana

final class ArcanaTests: XCTestCase {
    func testExample() throws {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct
        // results.

        let card = Arcana.getMajorString(0 as UInt32)
        let str = "0: THE FOOL"
        let swString: String = String(cString: card!)

        XCTAssertEqual(swString, str)
    }
}
