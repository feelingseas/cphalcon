<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Redis;

use IntegrationTester;

class ReadCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Redis :: read()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataRedisRead(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\MetaData\Redis - read()");
        $I->skipTest("Need implementation");
    }
}
