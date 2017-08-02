/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#define LITESHARES_SYMBOL "LTS"
#define LITESHARES_ADDRESS_PREFIX "LTS"

#define LITESHARES_MIN_ACCOUNT_NAME_LENGTH 1
#define LITESHARES_MAX_ACCOUNT_NAME_LENGTH 63

#define LITESHARES_MIN_ASSET_SYMBOL_LENGTH 3
#define LITESHARES_MAX_ASSET_SYMBOL_LENGTH 16

#define LITESHARES_MAX_SHARE_SUPPLY int64_t(1000000000000000ll)
#define LITESHARES_MAX_PAY_RATE 10000 /* 100% */
#define LITESHARES_MAX_SIG_CHECK_DEPTH 2
/**
 * Don't allow the committee_members to publish a limit that would
 * make the network unable to operate.
 */
#define LITESHARES_MIN_TRANSACTION_SIZE_LIMIT 1024
#define LITESHARES_MIN_BLOCK_INTERVAL   1 /* seconds */
#define LITESHARES_MAX_BLOCK_INTERVAL  30 /* seconds */

#define LITESHARES_DEFAULT_BLOCK_INTERVAL  5 /* seconds */
#define LITESHARES_DEFAULT_MAX_TRANSACTION_SIZE 2048
#define LITESHARES_DEFAULT_MAX_BLOCK_SIZE  (LITESHARES_DEFAULT_MAX_TRANSACTION_SIZE*LITESHARES_DEFAULT_BLOCK_INTERVAL*200000)
#define LITESHARES_DEFAULT_MAX_TIME_UNTIL_EXPIRATION (60*60*24) // seconds,  aka: 1 day
#define LITESHARES_DEFAULT_MAINTENANCE_INTERVAL  (60*60*24) // seconds, aka: 1 day
#define LITESHARES_DEFAULT_MAINTENANCE_SKIP_SLOTS 3  // number of slots to skip for maintenance interval

#define LITESHARES_MIN_UNDO_HISTORY 10
#define LITESHARES_MAX_UNDO_HISTORY 10000

#define LITESHARES_MIN_BLOCK_SIZE_LIMIT (LITESHARES_MIN_TRANSACTION_SIZE_LIMIT*5) // 5 transactions per block
#define LITESHARES_MIN_TRANSACTION_EXPIRATION_LIMIT (LITESHARES_MAX_BLOCK_INTERVAL * 5) // 5 transactions per block
#define LITESHARES_BLOCKCHAIN_PRECISION                           uint64_t( 100000 )

#define LITESHARES_BLOCKCHAIN_PRECISION_DIGITS                    5
#define LITESHARES_DEFAULT_TRANSFER_FEE                           (1*LITESHARES_BLOCKCHAIN_PRECISION)
#define LITESHARES_MAX_INSTANCE_ID                                (uint64_t(-1)>>16)
/** percentage fields are fixed point with a denominator of 10,000 */
#define LITESHARES_100_PERCENT                                    10000
#define LITESHARES_1_PERCENT                                      (LITESHARES_100_PERCENT/100)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define LITESHARES_MAX_MARKET_FEE_PERCENT                         LITESHARES_100_PERCENT
#define LITESHARES_DEFAULT_FORCE_SETTLEMENT_DELAY                 (60*60*24) ///< 1 day
#define LITESHARES_DEFAULT_FORCE_SETTLEMENT_OFFSET                0 ///< 1%
#define LITESHARES_DEFAULT_FORCE_SETTLEMENT_MAX_VOLUME            (20* LITESHARES_1_PERCENT) ///< 20%
#define LITESHARES_DEFAULT_PRICE_FEED_LIFETIME                    (60*60*24) ///< 1 day
#define LITESHARES_MAX_FEED_PRODUCERS                             200
#define LITESHARES_DEFAULT_MAX_AUTHORITY_MEMBERSHIP               10
#define LITESHARES_DEFAULT_MAX_ASSET_WHITELIST_AUTHORITIES        10
#define LITESHARES_DEFAULT_MAX_ASSET_FEED_PUBLISHERS              10

/**
 *  These ratios are fixed point numbers with a denominator of LITESHARES_COLLATERAL_RATIO_DENOM, the
 *  minimum maitenance collateral is therefore 1.001x and the default
 *  maintenance ratio is 1.75x
 */
///@{
#define LITESHARES_COLLATERAL_RATIO_DENOM                 1000
#define LITESHARES_MIN_COLLATERAL_RATIO                   1001  ///< lower than this could result in divide by 0
#define LITESHARES_MAX_COLLATERAL_RATIO                   32000 ///< higher than this is unnecessary and may exceed int16 storage
#define LITESHARES_DEFAULT_MAINTENANCE_COLLATERAL_RATIO   1250 ///< Call when collateral only pays off 175% the debt
#define LITESHARES_DEFAULT_MAX_SHORT_SQUEEZE_RATIO        1050 ///< Stop calling when collateral only pays off 150% of the debt
///@}
#define LITESHARES_DEFAULT_MARGIN_PERIOD_SEC              (30*60*60*24)

#define LITESHARES_DEFAULT_MIN_WITNESS_COUNT                    (11)
#define LITESHARES_DEFAULT_MIN_COMMITTEE_MEMBER_COUNT           (11)
#define LITESHARES_DEFAULT_MAX_WITNESSES                        (1001) // SHOULD BE ODD
#define LITESHARES_DEFAULT_MAX_COMMITTEE                        (1001) // SHOULD BE ODD
#define LITESHARES_DEFAULT_MAX_PROPOSAL_LIFETIME_SEC            (60*60*24*7*4) // Four weeks
#define LITESHARES_DEFAULT_COMMITTEE_PROPOSAL_REVIEW_PERIOD_SEC (60*60*24*7*2) // Two weeks
#define LITESHARES_DEFAULT_NETWORK_PERCENT_OF_FEE               (20*LITESHARES_1_PERCENT)
#define LITESHARES_DEFAULT_LIFETIME_REFERRER_PERCENT_OF_FEE     (30*LITESHARES_1_PERCENT)
#define LITESHARES_DEFAULT_MAX_BULK_DISCOUNT_PERCENT            (50*LITESHARES_1_PERCENT)
#define LITESHARES_DEFAULT_BULK_DISCOUNT_THRESHOLD_MIN          ( LITESHARES_BLOCKCHAIN_PRECISION*int64_t(1000) )
#define LITESHARES_DEFAULT_BULK_DISCOUNT_THRESHOLD_MAX          ( LITESHARES_DEFAULT_BULK_DISCOUNT_THRESHOLD_MIN*int64_t(100) )
#define LITESHARES_DEFAULT_CASHBACK_VESTING_PERIOD_SEC          (60*60*24*365) ///< 1 year
#define LITESHARES_DEFAULT_CASHBACK_VESTING_THRESHOLD           (LITESHARES_BLOCKCHAIN_PRECISION*int64_t(100))
#define LITESHARES_DEFAULT_BURN_PERCENT_OF_FEE                  (20*LITESHARES_1_PERCENT)
#define LITESHARES_WITNESS_PAY_PERCENT_PRECISION                (1000000000)
#define LITESHARES_DEFAULT_MAX_ASSERT_OPCODE                    1
#define LITESHARES_DEFAULT_FEE_LIQUIDATION_THRESHOLD            LITESHARES_BLOCKCHAIN_PRECISION * 100;
#define LITESHARES_DEFAULT_ACCOUNTS_PER_FEE_SCALE               1000
#define LITESHARES_DEFAULT_ACCOUNT_FEE_SCALE_BITSHIFTS          4
#define LITESHARES_DEFAULT_MAX_BUYBACK_MARKETS                  4

#define LITESHARES_MAX_WORKER_NAME_LENGTH                       63

#define LITESHARES_MAX_URL_LENGTH                               127

// counter initialization values used to derive near and far future seeds for shuffling witnesses
// we use the fractional bits of sqrt(2) in hex
#define LITESHARES_NEAR_SCHEDULE_CTR_IV                    ( (uint64_t( 0x6a09 ) << 0x30)    \
                                                         | (uint64_t( 0xe667 ) << 0x20)    \
                                                         | (uint64_t( 0xf3bc ) << 0x10)    \
                                                         | (uint64_t( 0xc908 )        ) )

// and the fractional bits of sqrt(3) in hex
#define LITESHARES_FAR_SCHEDULE_CTR_IV                     ( (uint64_t( 0xbb67 ) << 0x30)    \
                                                         | (uint64_t( 0xae85 ) << 0x20)    \
                                                         | (uint64_t( 0x84ca ) << 0x10)    \
                                                         | (uint64_t( 0xa73b )        ) )

/**
 * every second, the fraction of burned core asset which cycles is
 * LITESHARES_CORE_ASSET_CYCLE_RATE / (1 << LITESHARES_CORE_ASSET_CYCLE_RATE_BITS)
 */
#define LITESHARES_CORE_ASSET_CYCLE_RATE                        17
#define LITESHARES_CORE_ASSET_CYCLE_RATE_BITS                   32

#define LITESHARES_DEFAULT_WITNESS_PAY_PER_BLOCK            (LITESHARES_BLOCKCHAIN_PRECISION * int64_t( 10) )
#define LITESHARES_DEFAULT_WITNESS_PAY_VESTING_SECONDS      (60*60*24)
#define LITESHARES_DEFAULT_WORKER_BUDGET_PER_DAY            (LITESHARES_BLOCKCHAIN_PRECISION * int64_t(500) * 1000 )

#define LITESHARES_DEFAULT_MINIMUM_FEEDS                       7

#define LITESHARES_MAX_INTEREST_APR                            uint16_t( 10000 )

#define LITESHARES_RECENTLY_MISSED_COUNT_INCREMENT             4
#define LITESHARES_RECENTLY_MISSED_COUNT_DECREMENT             3

#define LITESHARES_CURRENT_DB_VERSION                          "LTS2.9"

#define LITESHARES_IRREVERSIBLE_THRESHOLD                      (70 * LITESHARES_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current committee members, two-week review period
#define LITESHARES_COMMITTEE_ACCOUNT (liteshares::chain::account_id_type(0))
/// Represents the current witnesses
#define LITESHARES_WITNESS_ACCOUNT (liteshares::chain::account_id_type(1))
/// Represents the current committee members
#define LITESHARES_RELAXED_COMMITTEE_ACCOUNT (liteshares::chain::account_id_type(2))
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define LITESHARES_NULL_ACCOUNT (liteshares::chain::account_id_type(3))
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define LITESHARES_TEMP_ACCOUNT (liteshares::chain::account_id_type(4))
/// Represents the canonical account for specifying you will vote directly (as opposed to a proxy)
#define LITESHARES_PROXY_TO_SELF_ACCOUNT (liteshares::chain::account_id_type(5))
/// Sentinel value used in the scheduler.
#define LITESHARES_NULL_WITNESS (liteshares::chain::witness_id_type(0))
///@}

#define LITESHARES_FBA_STEALTH_DESIGNATED_ASSET (asset_id_type(743))
